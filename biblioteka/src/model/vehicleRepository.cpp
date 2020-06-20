//
// Created by student on 18.06.2020.
//
#include "model/vehicleRepository.h"
#include <sstream>


VehicleRepository::VehicleRepository()
{
}

VehicleRepository::~VehicleRepository()
{
}

void VehicleRepository::addVehicle(VehiclePtr v)
{
    vehicleRepository.push_back(v);
}

void VehicleRepository::removeVehicle(VehiclePtr v)
{
    vehicleRepository.remove(v);
}

string VehicleRepository::getVehicle(unsigned int index)
{
    unsigned int i = 1;
    string chain = "";
    for (list<VehiclePtr>::iterator it = vehicleRepository.begin(); it != vehicleRepository.end(); it++)
    {
        if(i == index)
        {
            chain = (*it)->vehicleInfo();
        }
        i ++;
    }
    return chain;
}

string VehicleRepository::vehicleRaport()
{
    ostringstream chain;
    unsigned int i = 1;
    for (list<VehiclePtr>::iterator it = vehicleRepository.begin(); it != vehicleRepository.end(); it++)
    {
        chain<<i<< "- ";
        chain<<(*it)->vehicleInfo()<<endl;
        i++;
    }
    return chain.str();
}
