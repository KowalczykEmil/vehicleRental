//
// Created by student on 26.04.2020.
//
#include "model/client.h"


Client::Client(string imie, string nazwisko, string id, string ulica, int nrDomu, string ulica2, int nrDomu2)
        :firstName(imie), lastName(nazwisko), personalID(id), address(new Address(ulica, nrDomu)), registeredAddress(new Address(ulica2, nrDomu2))
{
}

Client::Client(const Client &c)
        :firstName(c.firstName), lastName(c.lastName), personalID(c.personalID), address(new Address(*c.address)), registeredAddress(new Address(*c.registeredAddress))
{
}

Client&Client:: operator= (const Client& c)
{
    delete address;
    delete registeredAddress;
    address = new Address(*c.address);
    registeredAddress = new Address(*c.registeredAddress);
    firstName = c.firstName;
    lastName = c.lastName;
    personalID = c.personalID;
    return *this;
}

Client::~Client()
{
    address = nullptr;
    registeredAddress = nullptr;
    delete address;
    delete registeredAddress;
    for(unsigned int i=0; i<rentVector.size(); i++)
    {
        rentVector[i] = nullptr;
        delete rentVector[i];
    }
}

void Client::clientInfo()
{
    int margin = 20;
    cout << "_________________________________________________" <<endl;
    cout << "Client Info:"<<endl;
    cout.width(margin); cout << left << "Name: ";
    cout << firstName + " " + lastName<<endl;
    cout.width(margin); cout << left << "Personal ID: ";
    cout << personalID <<endl;
    if (address != nullptr)
    {
        cout.width(margin); cout << left << "Address: ";
        cout << address->getStreet() + " " + to_string(address->getHouseNumber())<<endl;
    }
    if (registeredAddress != nullptr)
    {
        cout.width(20); cout << left << "Registered Address: ";
        cout << registeredAddress->getStreet() + " " + to_string(registeredAddress->getHouseNumber())<<endl;
    }
    allRents();
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
    adres = address->getStreet() + to_string(address->getHouseNumber());
    return adres;
}

string Client::getRegisteredAddress()
{
    string adres;
    adres = registeredAddress->getStreet() + to_string(registeredAddress->getHouseNumber());
    return adres;
}

void Client::addRent(Rent *r)
{
    rentVector.push_back(r);
}

void Client::allRents()
{
    for(unsigned int i=0; i<rentVector.size(); i++)
    {
        rentVector[i]->rentInfo();
        cout<<endl;
    }
}
