//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_RENTSREPOSITORY_H
#define POBIPROJECT_RENTSREPOSITORY_H
#include <string>
#include <list>
#include <memory>
//#include "model/repository.h"

using namespace std;
class Rent;
class RentsManager;
typedef shared_ptr<Rent> RentPtr;

class RentsRepository
{
private:
    list<RentPtr> rentRepositoryList{};
    friend class RentsManager;
public:
    void createRent(RentPtr);
    void removeRent(RentPtr);
    string rentReport();
    int getNumberOfRents();
};

#endif //POBIPROJECT_RENTSREPOSITORY_H
