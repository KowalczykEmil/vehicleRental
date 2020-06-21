//
// Created by student on 26.04.2020.
//
#include "model/client.h"
#include <sstream>
#include "model/address.h"
#include "model/rent.h"
#include "model/clientType.h"
#include "model/clientException.h"


Client::Client(string firstName_, string lastName_, string personalID_, string street_, int houseNumber_, string street__, int houseNumber__)
        :firstName(firstName_), lastName(lastName_), personalID(personalID_), address(new Address(street_, houseNumber_)), registeredAddress(new Address(street__, houseNumber__)),
         clientType(nullptr), balance(0)
{
    if (firstName.empty()) throw ClientException(ClientException::exceptionFirstName);
    if (lastName.empty()) throw ClientException(ClientException::exceptionLastName);
    if (personalID.empty()) throw ClientException(ClientException::exceptionPersonalID);
    if (address == nullptr or street_.empty() or houseNumber__ < 1) throw ClientException(ClientException::exceptionAddress);
    if (registeredAddress == nullptr or street__.empty() or houseNumber__ < 1) throw ClientException(ClientException::exceptionRegisteredAddress);
}

Client::Client(const Client &c)
        :firstName(c.firstName), lastName(c.lastName), personalID(c.personalID), address(new Address(*c.address)), registeredAddress(new Address(*c.registeredAddress)),
         clientType(c.clientType), balance(c.balance)
{
}

string Client::clientInfo()
{
    ostringstream chain;
    int margin = 20;
    chain << endl << "_________________________________________________" <<endl;
    chain << "Client Info:"<<endl;
    chain.width(margin); chain << left <<  "Name: ";
    chain << getFullName() <<endl;
    chain.width(margin); chain  << left << "Personal ID: ";
    chain << personalID <<endl;
    if (address != nullptr)
    {
        chain.width(margin); chain << left << "Address: ";
        chain << address->getAddress() <<endl;
    }
    if (registeredAddress != nullptr)
    {
        chain.width(20); chain << left << "Registered Address: ";
        chain << registeredAddress->getAddress() <<endl;
    }
    chain << allRents();
    return chain.str();
}

void Client::setLastName(string newLastName)
{
    if (newLastName.empty()) throw ClientException(ClientException::exceptionLastName);
    lastName = newLastName;
}

void Client::setAddress(Address newAddress)
{
    *address = newAddress;
    address->setStreet(address->getStreet());
    address->setHouseNumber(address->getHouseNumber());
}

void Client::setRegisteredAddress(Address newAddress)
{
    *registeredAddress = newAddress;
    registeredAddress->setStreet(registeredAddress->getStreet());
    registeredAddress->setHouseNumber(registeredAddress->getHouseNumber());
}


string Client::getFirstName()
{
    return firstName;
}

string Client::getLastName()
{
    return lastName;
}

string Client::getPersonalID()
{
    return personalID;
}

string Client::getAddress()
{
    string adres;
    adres = address->getStreet() + " " + to_string(address->getHouseNumber());
    return adres;
}

string Client::getRegisteredAddress()
{
    string adres;
    adres = registeredAddress->getStreet() + " " + to_string(registeredAddress->getHouseNumber());
    return adres;
}

void Client::archiveRent(RentPtr r)
{
    archivedRents.push_back(r);
}

string Client::allRents()
{
    ostringstream chain;
    for (const auto &rent : currentRents)
    {
        chain<<rent->rentInfo()<<endl;
    }
    for (const auto &rent : archivedRents)
    {
        chain<<rent->rentInfo()<<endl;
    }
    return chain.str();
}

string Client::getFullName()
{
    return firstName + " " + lastName;
}

void Client::setClientType(ClientTypePtr typeOfClient)
{
    clientType = ClientTypePtr(typeOfClient);
}

float Client::getDiscount()
{
    if (clientType == nullptr)
    {
        return 0;
    }
    return clientType->discount();
}

int Client::getVehicleLimit()
{
    if (clientType == nullptr)
    {
        return 1;
    }
    return clientType->vehicleLimit();
}

void Client::addCurrentRent(RentPtr r)
{
    currentRents.push_back(r);
}

void Client::removeArchiveRent(RentPtr r)
{
    currentRents.remove(r);
    archiveRent(r);
    setBalance(r);
}

int Client::getNumberOfRents()
{
    return currentRents.size();
}

int Client::getBalance()
{
    return balance;
}

void Client::setBalance(RentPtr r)
{
    balance += r -> getTotalPrice();
}

int Client::getNumberOfArchRents()
{
    return archivedRents.size();
}

vector<RentPtr> Client::getAllClientRents()
{
    vector<RentPtr> v{ begin(archivedRents), end(archivedRents) };
    return v;
}
