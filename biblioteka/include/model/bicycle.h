//
// Created by student on 18.06.2020.
//
#ifndef bicycleClass
#define bicycleClass
#include <string>
#include "model/vehicle.h"

using namespace std;

class Bicycle : public Vehicle
{
public:
    Bicycle(float, string);
    string vehicleInfo() override;
    float getPrice() override;
};
#endif //POBIPROJECT_BICYCLE_H
