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
private:
    float price;
    string registrationNumber;
public:
    Vehicle(float price, string registrationNumber);
    ~Vehicle();
    string vehicleInfo();
    float getPrice();
};
#endif //POBIPROJECT_VEHICLE_H
