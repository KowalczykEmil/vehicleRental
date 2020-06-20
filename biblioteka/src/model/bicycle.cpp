//
// Created by student on 18.06.2020.
//

#include "model/bicycle.h"


Bicycle::Bicycle(float cena, string nrRejestracja)
        : Vehicle(cena, nrRejestracja)
{
}

string Bicycle::vehicleInfo()
{
    string chain;
    chain = "BICYCLE: " + Vehicle::vehicleInfo() + ". Price: " + to_string(getPrice());
    return chain;
}

float Bicycle::getPrice()
{
    return Vehicle::getPrice();
}
