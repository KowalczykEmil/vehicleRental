//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H
#include <string>
#include <memory>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;
class Client;
class Vehicle;
class RentsManager;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Vehicle> VehiclePtr;

class Rent
{
private:
    uuid ID;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    float totalPrice;
    VehiclePtr vehicle;
    ClientPtr client;
    int rentalLength;
    friend class RentsManager;
public:
    Rent(ClientPtr, VehiclePtr, int=0);
    Rent(const Rent &r);
    Rent& operator= (const Rent&) = default;
    ~Rent();
    string rentInfo();
    void endRent();
    int getPeriod();
    float getPrice();
    string getClient();
    string getVehicleRented();
    local_date_time getRentDate();
    local_date_time getEndDate();
    int getRentalLength();
    int getTotalPrice();
    uuid getID();
};


#endif //POBIPROJECT_RENT_H
