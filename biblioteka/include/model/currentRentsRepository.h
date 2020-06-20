//
// Created by student on 18.06.2020.
//

#ifndef POBIPROJECT_CURRENTRENTSREPOSITORY_H
#define POBIPROJECT_CURRENTRENTSREPOSITORY_H
#include <string>
#include <list>
#include "model/rent.h"
#include <memory>



using namespace std;

class Rent;


class CurrentRentsRepository
{
private:
    list<shared_ptr<Rent>> rentRepositoryList{};
public:
    void createRent(shared_ptr<Rent>);
    void removeRent(shared_ptr<Rent>);
    string getClientForRentedVehicle(shared_ptr<Vehicle>);
    string rentReport();
    CurrentRentsRepository();
    ~CurrentRentsRepository();

};

#endif //POBIPROJECT_CURRENTRENTSREPOSITORY_H
