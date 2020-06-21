//
// Created by student on 18.06.2020.
//
#ifndef POBIPROJECT_MOTORVEHICLE_H
#define POBIPROJECT_MOTORVEHICLE_H
#include <string>
#include "vehicle.h"

using namespace std;

class MotorVehicle : public Vehicle
{
private:
    float engineDisplacement;
    double getWage() const;
public:
    MotorVehicle(const int&, const string&, const float&);
    virtual ~MotorVehicle()= default;
    const float& getEngineDisplacement() const;
    string vehicleInfo() const override;
    int getPrice() const override;
};

#endif //POBIPROJECT_MOTORVEHICLE_H
