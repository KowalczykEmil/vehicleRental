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

void Vehicle::vehicleInfo()
{
    cout << "Registration number :"<<registrationNumber<<". Price: "<< price <<endl;
}

float Vehicle::getPrice()
{
    return price;
}
string Vehicle::getRegistrationNumber()
{
    return registrationNumber;
}
