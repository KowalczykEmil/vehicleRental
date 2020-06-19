//
// Created by student on 18.06.2020.
//

#include "model/bicycle.h"


Bicycle::Bicycle(float cena, string nrRejestracja)
        : Vehicle(cena, nrRejestracja)
{
}

void Bicycle::vehicleInfo()
{
    cout << "BICYCLE: Registration number :"<<registrationNumber<<". Price: "<< price <<endl;
}

Bicycle::~Bicycle()
{
}
