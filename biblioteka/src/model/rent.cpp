//
// Created by student on 17.06.2020.
#include "model/rent.h"
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp> // generators
#include "boost/date_time/local_time/local_time.hpp"


time_zone_ptr timeZone(new posix_time_zone("CET+0"));

Rent::Rent(shared_ptr<Client> klient, shared_ptr<Vehicle> pojazd)
        : ID(random_generator()()), rentDateTime(nullptr), endDateTime(nullptr), totalPrice(0), vehicle(pojazd), client(klient), rentalLength(0)
{
    ptime lt(second_clock::local_time());
    rentDateTime = new local_date_time(lt, timeZone);
    client -> addRent(this);
}

Rent::Rent(const Rent &r)
        :ID(r.ID), rentDateTime(new local_date_time(*r.rentDateTime)),
         endDateTime(new local_date_time(*r.endDateTime)), totalPrice(r.totalPrice), vehicle(new Vehicle(*r.vehicle)), client(new Client(*r.client)), rentalLength(r.rentalLength)
{
}

Rent&Rent:: operator= (const Rent&)
{
    return *this;
}

Rent::~Rent()
{
    delete rentDateTime;
    delete endDateTime;
}

void Rent::endRent()
{
    ptime lt(second_clock::local_time());
    endDateTime = new local_date_time(lt, timeZone);
    rentalLength = getPeriod() + 1;
    totalPrice = rentalLength * vehicle -> getPrice();
}

int Rent::getPeriod()
{
    int daysOfRental;
    ptime lt(second_clock::local_time());
    local_date_time *nowTime = new local_date_time(lt, timeZone);
    time_duration period = local_time_period(*rentDateTime, *nowTime).length();
    daysOfRental = period.hours()/24;
    return daysOfRental;
}

string Rent::rentInfo()
{
    ostringstream chain;
    int margin = 20;
    chain << endl << "_________________________________________________" <<endl;
    chain << "Rental info:" <<endl;
    chain.width(margin); chain << left << "UUID: ";
    chain << ID << endl;
    chain.width(margin); chain << left << "Rental Date: ";
    chain << (*rentDateTime).local_time()<<endl;
    if (endDateTime != nullptr)
    {
        chain.width(margin); chain << left << "End of rental: ";
        chain << (*endDateTime).local_time()<<endl;
    }
    chain.width(margin); chain << left <<  "Period: ";
    chain << rentalLength <<endl;
    chain.width(margin); chain << left << "Client: ";
    chain << client->getFirstName() + " " + client->getLastName()<<endl;
    chain.width(margin); chain << left << "Vehicle: ";
    chain << vehicle->getRegistrationNumber()<<endl;
    return chain.str();
}

float Rent::getPrice()
{
    return totalPrice;
}

string Rent::getClient()
{
    return client->getPersonalID();
}

string Rent::getVehicleRented()
{
    return vehicle->getRegistrationNumber();
}

local_date_time Rent::getRentDate()
{
    return *rentDateTime;
}

local_date_time Rent::getEndDate()
{
    return *endDateTime;
}

int Rent::getRentalLength()
{
    return rentalLength;
}


//


