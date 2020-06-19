//
// Created by student on 17.06.2020.
//

#include "model/vehicle.h"


Vehicle::Vehicle(float cena, string nrRejestracja)
{
    price = cena;
    registrationNumber = nrRejestracja;
}

Vehicle::~Vehicle()
{
}

string Vehicle::vehicleInfo()
{
    string info;
    info = registrationNumber;
    return info;
}

float Vehicle::getPrice()
{
    return price;
}
