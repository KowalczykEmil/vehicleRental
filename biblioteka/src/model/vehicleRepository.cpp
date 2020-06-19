//
// Created by student on 18.06.2020.
//
#include "model/vehicleRepository.h"



VehicleRepository::VehicleRepository()
{
}

VehicleRepository::~VehicleRepository()
{
}

void VehicleRepository::addVehicle(Vehicle *v)
{
    vehicleRepository.push_back(v);
}

void VehicleRepository::removeVehicle(Vehicle *v)
{
    vehicleRepository.remove(v);
}

void VehicleRepository::getVehicle(unsigned int index)
{
    unsigned int i = 1;
    for (list<Vehicle*>::iterator it = vehicleRepository.begin(); it != vehicleRepository.end(); it++)
    {
        if(i == index)
        {
            (*it)->vehicleInfo();
        }
        i ++;
    }
}

void VehicleRepository::vehicleRaport()
{
    unsigned int i = 1;
    for (list<Vehicle*>::iterator it = vehicleRepository.begin(); it != vehicleRepository.end(); it++)
    {
        cout<<i<< "- ";
        (*it)->vehicleInfo();
        i++;
    }
}

