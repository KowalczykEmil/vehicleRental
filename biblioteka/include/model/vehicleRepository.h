//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H
#include <string>
#include <list>
#include <memory>
//#include "model/repository.h"

using namespace std;
class Vehicle;
class VehicleManager;
typedef shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository
{
private:
    list<VehiclePtr> vehicleRepository{};
    friend class VehicleManager;
public:
    void addVehicle(VehiclePtr);
    void removeVehicle(VehiclePtr);
    string getVehicle(unsigned int index);
    string vehicleRaport();
};

#endif //POBIPROJECT_VEHICLEREPOSITORY_H
