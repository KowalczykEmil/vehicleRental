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
    float getWage();
public:
    Car(float, string, float, char);
    string vehicleInfo() override;
    float getPrice() override;
};
#endif //POBIPROJECT_CAR_H
