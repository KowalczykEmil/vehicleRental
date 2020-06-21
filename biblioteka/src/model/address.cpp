//
// Created by student on 15.06.2020.
//

#include "model/address.h"
#include "model/addressException.h"


Address::Address(string street_, int houseNumber_)
        : street(street_), houseNumber(houseNumber_)
{
    if (street.empty()) throw AddressException(AddressException::exceptionStreet);
    if (houseNumber <= 0) throw AddressException(AddressException::exceptionHouseNumber);
}

void Address::setStreet(string newStreet)
{
    street = newStreet;
    if (street.empty()) throw AddressException(AddressException::exceptionStreet);
}

void Address::setHouseNumber(int newHouseNumber)
{
    houseNumber = newHouseNumber;
    if (houseNumber <= 0) throw AddressException(AddressException::exceptionHouseNumber);
}

string Address::getStreet()
{
    return street;
}

int Address::getHouseNumber()
{
    return houseNumber;
}

string Address::getAddress()
{
    return getStreet() + " " + to_string(getHouseNumber());
}

void Address::setAddress(string newStreet, int number)
{
    setStreet(newStreet);
    setHouseNumber(number);
    if (street.empty()) throw AddressException(AddressException::exceptionStreet);
    if (houseNumber <= 0) throw AddressException(AddressException::exceptionHouseNumber);
}
