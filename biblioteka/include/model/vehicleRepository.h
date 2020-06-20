//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H
#include <string>
#include <list>
#include "model/vehicle.h"


using namespace std;


class VehicleRepository
{
private:
    list<VehiclePtr> vehicleRepository{};
public:
    VehicleRepository();
    ~VehicleRepository();
    void addVehicle(VehiclePtr);
    void removeVehicle(VehiclePtr);
    string getVehicle(unsigned int index);
    string vehicleRaport();
};
#endif //POBIPROJECT_VEHICLEREPOSITORY_H
