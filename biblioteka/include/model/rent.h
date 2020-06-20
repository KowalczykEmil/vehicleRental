//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H
#include <string>
#include "model/vehicle.h"
#include "model/client.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include "model/currentRentsRepository.h"
#include <memory>


using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;


class Client;


class Rent
{
private:
    uuid ID;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    float totalPrice;
    shared_ptr<Vehicle> vehicle;
    shared_ptr<Client> client;
    int rentalLength;
    friend class CurrentRentsRepository;
public:
    Rent(shared_ptr<Client>, shared_ptr<Vehicle>);
    Rent& operator= (const Rent&);
    Rent(const Rent &r);
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
};
typedef shared_ptr<Rent> RentPtr;

#endif //POBIPROJECT_RENT_H
