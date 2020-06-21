#include "model/moped.h"


Moped::Moped(float price, string registrationNumber, float engineDisplacement)
        : MotorVehicle(price, registrationNumber, engineDisplacement)
{
}

string Moped::vehicleInfo()
{
    string chain;
    chain = "MOPED: " + MotorVehicle::vehicleInfo() + ". Price: " + to_string(getPrice());
    return chain;
}
