//
// Created by student on 18.06.2020.
//
#include "model/currentRentsRepository.h"


CurrentRentsRepository::CurrentRentsRepository()
{
}


CurrentRentsRepository::~CurrentRentsRepository()
{
    for (list<Rent*>::iterator it = rentRepositoryList.begin(); it != rentRepositoryList.end(); it++)
    {
        (*it)=nullptr;
        delete *it;
    }
}

void CurrentRentsRepository::createRent(Rent *r)
{
    list<Rent *>::iterator it;
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
    else
    {
        cout<<endl<<"This vehicle is already rented"<<endl;
    }
}

void CurrentRentsRepository::removeRent(Rent *r)
{
    rentRepositoryList.remove(r);
}

void CurrentRentsRepository::getClientForRentedVehicle(Vehicle *v)
{
    list<Rent *>::iterator it;
    for(it = rentRepositoryList.begin(); it != rentRepositoryList.end(); ++it)
    {
        if((*it)->vehicle == v)
        {
            (*it)->client->clientInfo();
            break;
        }
    }
}

void CurrentRentsRepository::rentReport()
{
    for (list<Rent*>::iterator it = rentRepositoryList.begin(); it != rentRepositoryList.end(); it++)
        (*it)->rentInfo();
}

