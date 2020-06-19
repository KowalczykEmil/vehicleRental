//
// Created by student on 26.04.2020.
//
#include <string>
#include "model/client.h"

using namespace std;

Client::Client()
{
    cout << "Wywolano konstruktor bezparametrowy" << endl;
}


Client::Client(string imie, string nazwisko, string id, string adres)
{
    firstName = imie;
    lastName = nazwisko;
    personalID = id;
    address = adres;
    cout << "Wywolano konstruktor parametrowy" << endl;
}


Client::~Client()
{
    cout << "Wywolano destruktor" << endl;
}

string Client::clientInfo()
{
    string chain;
    chain = firstName + lastName + personalID + address;
    return chain;
}

void Client::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Client::setAddress(string newAddress)
{
    address = newAddress;
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
    return address;
}
