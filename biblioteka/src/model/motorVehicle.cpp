//
// Created by student on 18.06.2020.
//
#include "model/motorVehicle.h"


MotorVehicle::MotorVehicle(float price, string registrationNumber, float engineCapacity)
        : Vehicle(price, registrationNumber), engineDisplacement(engineCapacity)
{
}

MotorVehicle::~MotorVehicle()
{
}

float MotorVehicle::getEngineDisplacement()
{
    return engineDisplacement;
}

string MotorVehicle::vehicleInfo()
{
    string chain;
    chain = Vehicle::vehicleInfo() + ". Engine displacement: " + to_string(engineDisplacement);
    return chain;
}

float MotorVehicle::getWage()
{
    float wage = 0;
    if (engineDisplacement < 1000)
    {
        wage = 1;
    }
    else if (engineDisplacement >= 1000 and engineDisplacement < 2000)
    {
        wage = 1 + (engineDisplacement - 1000) / 1000 * 0.5;
    }
    else if (engineDisplacement >= 2000)
    {
        wage = 1.5;
    }
    return wage;
}

float MotorVehicle::getPrice()
{
    return Vehicle::getPrice() * getWage();
}

