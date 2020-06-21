//
// Created by student on 18.06.2020.
//
#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include <sstream>
#include <algorithm>
#include "model/vehicleRepositoryException.h"


void VehicleRepository::addVehicle(VehiclePtr v)
{
    if (v == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    for(const auto &vehicle : vehicleRepository)
    {
        if(vehicle -> getRegistrationNumber() == v -> getRegistrationNumber())
        {
            throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
        }
    }
    vehicleRepository.push_back(v);
}

void VehicleRepository::removeVehicle(VehiclePtr v)
{
    if (v == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    bool found = (find(vehicleRepository.begin(), vehicleRepository.end(), v) != vehicleRepository.end());
    if (!found) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
    vehicleRepository.remove(v);
}

string VehicleRepository::getVehicle(unsigned int index)
{
    if (index > vehicleRepository.size()) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
    unsigned int i = 1;
    string chain;
    for(const auto& v : vehicleRepository)
    {
        if(i == index)
        {
            chain = v->vehicleInfo();
        }
        i ++;
    }
    return chain;
}

string VehicleRepository::vehicleRaport()
{
    ostringstream chain;
    unsigned int i = 1;
    for(const auto& v : vehicleRepository)
    {
        chain<<i<< "- ";
        chain<<v->vehicleInfo()<<endl;
        i++;
    }
    return chain.str();
}

