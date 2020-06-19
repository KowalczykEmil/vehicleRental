//
// Created by student on 18.06.2020.
//

#ifndef POBIPROJECT_CAR_H
#define POBIPROJECT_CAR_H
#include <string>
#include <iostream>
#include "model/motorVehicle.h"

using namespace std;

class Car : public MotorVehicle
{
private:
    char segment;
    void setPrice();
public:
    Car(float price, string registrationNumber, float engineDisplacement, char seg);
    ~Car();
    void vehicleInfo();
};


#endif //POBIPROJECT_CAR_H
