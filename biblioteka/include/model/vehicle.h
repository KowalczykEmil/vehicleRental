//
// Created by student on 17.06.2020.
//
#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H
#include <string>
#include <memory>


using namespace std;

class Vehicle
{
private:
    float price;
    string registrationNumber;
public:
    Vehicle(float price, string registrationNumber);
    virtual ~Vehicle();
    virtual string vehicleInfo();
    virtual float getPrice();
    string getRegistrationNumber();
};
typedef shared_ptr<Vehicle> VehiclePtr;

#endif //POBIPROJECT_VEHICLE_H
