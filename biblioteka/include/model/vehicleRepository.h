//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H
#include <string>
#include <list>
#include <memory>
#include "model/repository.h"

using namespace std;
class Vehicle;
class VehicleManager;
typedef shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository : Repository<Vehicle>
{
private:
    list<VehiclePtr> vehicleRepository{};
public:
    void create(const VehiclePtr&) override;
    void remove(const VehiclePtr&) override;
    const VehiclePtr& search(const unsigned int&) const override;
    string getAll() const override;
    const list<VehiclePtr>& getRepository() const override;
};

#endif //POBIPROJECT_VEHICLEREPOSITORY_H
