//
// Created by student on 18.06.2020.
//

#ifndef POBIPROJECT_CURRENTRENTSREPOSITORY_H
#define POBIPROJECT_CURRENTRENTSREPOSITORY_H
#include <string>
#include <iostream>
#include <list>
#include "model/rent.h"
#include "model/vehicle.h"

using namespace std;

class Rent;

class CurrentRentsRepository
{
private:
    list<Rent *> rentRepositoryList{};
public:
    void createRent(Rent *);
    void removeRent(Rent *);
    void getClientForRentedVehicle(Vehicle *);
    void rentReport();
    void createStaticCopy();
    CurrentRentsRepository();
    ~CurrentRentsRepository();

};
#endif //POBIPROJECT_CURRENTRENTSREPOSITORY_H
