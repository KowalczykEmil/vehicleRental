//
// Created by student on 18.06.2020.
//
#ifndef POBIPROJECT_MOTORVEHICLE_H
#define POBIPROJECT_MOTORVEHICLE_H
#include <string>
#include "vehicle.h"

using namespace std;

class MotorVehicle : public Vehicle
{
private:
    float engineDisplacement;
    float getWage();
public:
    MotorVehicle(float price, string registrationNumber, float engineCapacity);
    virtual ~MotorVehicle()= default;
    float getEngineDisplacement();
    string vehicleInfo() override;
    float getPrice() override;
};

#endif //POBIPROJECT_MOTORVEHICLE_H
