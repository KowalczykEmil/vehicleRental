//
// Created by student on 18.06.2020.
//
#include "model/car.h"
#include <iostream>


Car::Car(float price, string registrationNumber, float engineDisplacement, char seg)
        : MotorVehicle(price, registrationNumber, engineDisplacement), segment(seg)
{
}

string Car::vehicleInfo()
{
    string chain;
    chain = "CAR: " + MotorVehicle::vehicleInfo() + ". Price: " + to_string(getPrice()) + ". Car class: " + segment;
    return chain;
}

float Car::getWage()
{
    float wage = 0;
    if(segment == 'A')
    {
        wage = 1;
    }
    else if(segment == 'B')
    {
        wage = 1.1;
    }
    else if(segment == 'C')
    {
        wage = 1.2;
    }
    else if(segment == 'D')
    {
        wage = 1.3;
    }
    else if(segment == 'E')
    {
        wage = 1.5;
    }
    return wage;
}

float Car::getPrice()
{
    return MotorVehicle::getPrice() * getWage();
}



