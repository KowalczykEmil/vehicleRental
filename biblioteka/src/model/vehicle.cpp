//
// Created by student on 17.06.2020.
//

#include "model/vehicle.h"


Vehicle::Vehicle(float cena, string nrRejestracja): price(cena), registrationNumber(nrRejestracja)
{
}

Vehicle::~Vehicle()
{
}

string Vehicle::vehicleInfo()
{
    string chain;
    chain = "Registration number :" + registrationNumber;
    return chain;
}

float Vehicle::getPrice()
{
    return price;
}
string Vehicle::getRegistrationNumber()
{
    return registrationNumber;
}