//
// Created by student on 19.06.2020.
//

#include "model/vehicleManager.h"
#include "model/clientGold.h"
#include "model/rent.h"
#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/vehicleRepositoryException.h"


VehicleManager::VehicleManager()
        : currentVehicles(new VehicleRepository), archiveVehicles(new VehicleRepository)
{
}

void VehicleManager::addVehicle(VehiclePtr vehicle)
{
    bool exists = false;
    bool archived = false;
    for(const auto& v : currentVehicles->vehicleRepository)
    {
        if(vehicle -> getRegistrationNumber() == v->getRegistrationNumber())
        {
            exists = true;
            break;
        }
    }
    for(const auto& v : archiveVehicles->vehicleRepository)
    {
        if(vehicle->getRegistrationNumber() == v->getRegistrationNumber())
        {
            archived = true;
            break;
        }
    }
    if(exists)
    {
        throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
    }
    else
    {
        if(archived)
        {
            archiveVehicles -> removeVehicle(vehicle);
        }
        currentVehicles -> addVehicle(vehicle);
    }
}

void VehicleManager::removeVehicle(VehiclePtr vehicle)
{
    currentVehicles -> removeVehicle(vehicle);
    archiveVehicles -> addVehicle(vehicle);
}

int VehicleManager::getNumberOfCurrentVehicles()
{
    return currentVehicles -> vehicleRepository.size();
}

int VehicleManager::getNumberOfArchVehicles()
{
    return archiveVehicles -> vehicleRepository.size();
}

