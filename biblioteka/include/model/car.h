//
// Created by student on 18.06.2020.
//
#ifndef POBIPROJECT_CAR_H
#define POBIPROJECT_CAR_H
#include <string>
#include "model/motorVehicle.h"

using namespace std;

class Car : public MotorVehicle
{
private:
    char segment;
    double getWage() const;
public:
    Car(const int&, const string&, const float&, const char&);
    string vehicleInfo() const override;
    int getPrice() const override;
};
#endif //POBIPROJECT_CAR_H
