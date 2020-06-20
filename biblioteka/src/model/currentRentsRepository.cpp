//
// Created by student on 18.06.2020.
//
#include "model/currentRentsRepository.h"
#include <sstream>

CurrentRentsRepository::CurrentRentsRepository()
{
}


CurrentRentsRepository::~CurrentRentsRepository()
{
}

void CurrentRentsRepository::createRent(shared_ptr<Rent> r)
{
    list<shared_ptr<Rent>>::iterator it;
    bool isRented = false;
    for(it = rentRepositoryList.begin(); it != rentRepositoryList.end(); ++it)
    {
        if(r->vehicle->getRegistrationNumber() == (*it)->vehicle->getRegistrationNumber())
        {
            isRented = true;
            break;
        }
    }
    if(isRented == false)
    {
        rentRepositoryList.push_back(r);
    }
}
void CurrentRentsRepository::removeRent(shared_ptr<Rent> r)
{
    rentRepositoryList.remove(r);
}

string CurrentRentsRepository::getClientForRentedVehicle(shared_ptr<Vehicle> v)
{
    string clientInfo = "";
    list<shared_ptr<Rent>>::iterator it;
    for(it = rentRepositoryList.begin(); it != rentRepositoryList.end(); ++it)
    {
        if((*it)->vehicle == v)
        {
            clientInfo = (*it)->client->clientInfo();
            break;
        }
    }
    return clientInfo;
}

string CurrentRentsRepository::rentReport()
{
    ostringstream chain;
    for (list<shared_ptr<Rent>>::iterator it = rentRepositoryList.begin(); it != rentRepositoryList.end(); it++)
        chain<<(*it)->rentInfo();
    return chain.str();
}




