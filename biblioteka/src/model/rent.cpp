//
// Created by student on 17.06.2020.
#include "model/rent.h"
#include <sstream>


Rent::Rent(Client &klient, Vehicle &pojazd)
{
    client = &klient;
    vehicle = &pojazd;
    timeZone = new time_zone_ptr(new posix_time_zone("CET+0"));
    ptime pt(second_clock::local_time());
    rentDateTime = new local_date_time(pt, *timeZone);
    endDateTime = nullptr;
    ID = boost::uuids::random_generator()();
    totalPrice = 0;
    rentalLength = 0;
    client -> addRent(this);
}

Rent::~Rent()
{
    rentDateTime = nullptr;
    endDateTime = nullptr;
    timeZone = nullptr;
    delete rentDateTime;
    delete endDateTime;
    delete timeZone;
}

void Rent::endRent()
{
    ptime lt(second_clock::local_time());
    local_date_time *nowTime = new local_date_time(lt, *timeZone);
    endDateTime = nowTime;
    rentalLength = getPeriod() + 1;
    totalPrice = rentalLength * vehicle -> getPrice();
}

int Rent::getPeriod()
{
    int daysOfRental;
    ptime lt(second_clock::local_time());
    local_date_time *nowTime = new local_date_time(lt, *timeZone);
    time_duration period = local_time_period(*rentDateTime, *nowTime).length();
    daysOfRental = period.hours()/24;
    return daysOfRental;
}

void Rent::rentInfo()
{
    int margin = 20;
    ostringstream stream1, stream2;
    cout << "_________________________________________________" <<endl;
    cout << "Rental info:" <<endl;
    cout.width(margin); cout << left << "UUID: ";
    cout << ID << endl;
    cout.width(margin); cout << left << "Rental Date: ";
    stream1 << (*rentDateTime).local_time()<<endl;
    cout << stream1.str();
    if (endDateTime != nullptr)
    {
        cout.width(margin); cout << left << "End of rental: ";
        stream2 << (*endDateTime).local_time();
        cout << stream2.str() << endl;
    }
    cout.width(margin); cout << left <<  "Period: ";
    cout << rentalLength <<endl;
    cout.width(margin); cout << left << "Client: ";
    cout << client->getFirstName() + " " + client->getLastName()<<endl;
    cout.width(margin); cout << left << "Vehicle: ";
    cout << vehicle->vehicleInfo()<<endl;
}

float Rent::getPrice()
{
    return totalPrice;
}

string Rent::getClient()
{
    return client->getFirstName() + client->getLastName();
}

string Rent::getVehicleRented()
{
    return vehicle->vehicleInfo();
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

