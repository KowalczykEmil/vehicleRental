//
// Created by student on 18.06.2020.
//
#ifndef POBIPROJECT_MOPED_H
#define POBIPROJECT_MOPED_H
#include <string>
#include "model/motorVehicle.h"

using namespace std;

class Moped : public MotorVehicle
{
public:
    Moped(const int&, const string&, const float&);
    string vehicleInfo() const override;
};

#endif //POBIPROJECT_MOPED_H
