//
// Created by student on 18.06.2020.
//

#ifndef POBIPROJECT_BICYCLE_H
#define POBIPROJECT_BICYCLE_H
#ifndef bicycleClass
#define bicycleClass
#include <string>
#include <iostream>
#include "model/vehicle.h"

using namespace std;

class Bicycle : public Vehicle
{
public:
    Bicycle(float price, string registrationNumber);
    ~Bicycle();
    void vehicleInfo();
};
#endif

#endif //POBIPROJECT_BICYCLE_H
