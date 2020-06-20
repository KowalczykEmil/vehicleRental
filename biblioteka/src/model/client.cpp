//
// Created by student on 26.04.2020.
//
#include "model/client.h"
#include <sstream>


Client::Client(string imie, string nazwisko, string id, string ulica, int nrDomu, string ulica2, int nrDomu2)
        :firstName(imie), lastName(nazwisko), personalID(id), address(new Address(ulica, nrDomu)), registeredAddress(new Address(ulica2, nrDomu2))
{
}

Client::Client(const Client &c)
        :firstName(c.firstName), lastName(c.lastName), personalID(c.personalID), address(new Address(*c.address)), registeredAddress(new Address(*c.registeredAddress))
{
}

Client::~Client()
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

void Client::addRent(Rent *r)
{
    rentVector.push_back(r);
}

string Client::allRents()
{
    ostringstream chain;
    for(unsigned int i=0; i<rentVector.size(); i++)
    {
        chain<<rentVector[i]->rentInfo()<<endl;
    }
    return chain.str();
}

string Client::getFullName()
{
    return firstName + " " + lastName;
}
