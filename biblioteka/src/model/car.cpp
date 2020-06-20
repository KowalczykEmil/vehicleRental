//
// Created by student on 18.06.2020.
//
#include "model/car.h"


Car::Car(float price, string registrationNumber, float engineDisplacement, char seg)
        : MotorVehicle(price, registrationNumber, engineDisplacement), segment(seg)
{
    setPrice();
}

Car::~Car()
{
}

void Car::vehicleInfo()
{
    cout << "CAR: Registration number :"<<registrationNumber<<". Price: "<< price <<". Engine displacement: "<<engineDisplacement<<". Car class: "<<segment<<endl;
}

void Car::setPrice()
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

    price = wage * MotorVehicle::price;
}



