//
// Created by student on 18.06.2020.
//
#include "model/moped.h"


Moped::Moped(float price, string registrationNumber, float engineDisplacement)
        : MotorVehicle(price, registrationNumber, engineDisplacement)
{
}

void Moped::vehicleInfo()
{
    cout << "MOPED: Registration number :"<<registrationNumber<<". Price: "<< price <<". Engine displacement: "<<engineDisplacement<<endl;
}

Moped::~Moped()
{
}

