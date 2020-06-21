//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_VEHICLEMENAGER_H
#define POBIPROJECT_VEHICLEMENAGER_H
#include <memory>
#include <vector>
#include <string>

using namespace std;
class Vehicle;
class VehicleRepository;
typedef shared_ptr<Vehicle> VehiclePtr;

class VehicleManager{
    shared_ptr<VehicleRepository> currentVehicles;
    shared_ptr<VehicleRepository> archiveVehicles;
public:
    VehicleManager();
    void addVehicle(const VehiclePtr&);
    void removeVehicle(const VehiclePtr&);
    int getNumberOfArchVehicles() const;
    int getNumberOfCurrentVehicles() const;
};

#endif //POBIPROJECT_VEHICLEMENAGER_H
