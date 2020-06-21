//
// Created by student on 17.06.2020.
//

#include "model/vehicle.h"
#include "model/vehicleException.h"


Vehicle::Vehicle(float price_, string registrationNumber_): price(price_), registrationNumber(registrationNumber_)
{
    if (price <= 0) throw VehicleException(VehicleException::exceptionPrice);
    if (registrationNumber.empty()) throw VehicleException(VehicleException::exceptionRegistration);
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