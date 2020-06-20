//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H
#include <string>
#include <iostream>
#include "model/vehicle.h"
#include "model/client.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>
#include "model/currentRentsRepository.h"
#include <sstream>
#include <list>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

class Client;

class Rent
{
private:
    uuid ID;
    time_zone_ptr *timeZone;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    float totalPrice;
    Vehicle *vehicle;
    Client *client;
    int rentalLength;
    friend class CurrentRentsRepository;
public:
    Rent(Client &klient, Vehicle &pojazd);
    Rent(const Rent &r);
    Rent& operator= (const Rent&);
    ~Rent();
    void rentInfo();
    void endRent();
    int getPeriod();
    float getPrice();
    string getClient();
    string getVehicleRented();
    local_date_time getRentDate();
    local_date_time getEndDate();
    int getRentalLength();
};
#endif //POBIPROJECT_RENT_H
