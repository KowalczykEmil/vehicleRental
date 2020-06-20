//
// Created by student on 18.06.2020.
//
#ifndef POBIPROJECT_MOPED_H
#define POBIPROJECT_MOPED_H
#include <string>
#include <iostream>
#include "model/motorVehicle.h"

using namespace std;

class Moped : public MotorVehicle
{
public:
    Moped(float price, string registrationNumber, float engineDisplacement);
    ~Moped();
    void vehicleInfo();
};
#endif //POBIPROJECT_MOPED_H
