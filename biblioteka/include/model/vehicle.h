//
// Created by student on 17.06.2020.
//
#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H
#include <string>
#include <iostream>

using namespace std;

class Vehicle
{
protected:
    float price;
    string registrationNumber;
public:
    Vehicle(float price, string registrationNumber);
    virtual ~Vehicle();
    virtual void vehicleInfo();
    virtual float getPrice();
    virtual string getRegistrationNumber();
};
#endif //POBIPROJECT_VEHICLE_H
