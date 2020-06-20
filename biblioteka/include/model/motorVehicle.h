//
// Created by student on 18.06.2020.
//
#ifndef POBIPROJECT_MOTORVEHICLE_H
#define POBIPROJECT_MOTORVEHICLE_H
#include <string>
#include <iostream>
#include "vehicle.h"

using namespace std;

class MotorVehicle : public Vehicle
{
protected:
    float engineDisplacement;
    void setPrice();
    MotorVehicle(float price, string registrationNumber, float engineCapacity);
public:
    ~MotorVehicle();
    float getEngineDisplacement();
};
#endif //POBIPROJECT_MOTORVEHICLE_H
