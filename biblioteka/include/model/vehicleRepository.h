//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H
#include <string>
#include <iostream>
#include "model/bicycle.h"
#include "model/car.h"
#include "model/moped.h"
#include <list>


using namespace std;


class VehicleRepository
{
private:
    list<Vehicle *> vehicleRepository{};
public:
    VehicleRepository();
    ~VehicleRepository();
    void addVehicle(Vehicle *);
    void removeVehicle(Vehicle *v);
    void getVehicle(unsigned int index);
    void vehicleRaport();
};
#endif //POBIPROJECT_VEHICLEREPOSITORY_H
