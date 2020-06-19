//
// Created by student on 15.06.2020.
//

#include "model/address.h"


Address::Address(string ulica, int numerDomu)
{
    street = ulica;
    houseNumber = numerDomu;
}

Address::~Address()
{
}


void Address::setStreet(string newStreet)
{
    street = newStreet;
}

void Address::setHouseNumber(int newHouseNumber)
{
    houseNumber = newHouseNumber;
}

string Address::getStreet()
{
    return street;
}

int Address::getHouseNumber()
{
    return houseNumber;
}
