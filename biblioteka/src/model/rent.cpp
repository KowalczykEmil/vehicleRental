//
// Created by student on 17.06.2020.
#include "model/rent.h"


Rent::Rent(Client &klient, Vehicle &pojazd)
        :ID(random_generator()()), timeZone(new time_zone_ptr(new posix_time_zone("CET+0"))),
         rentDateTime(new local_date_time((second_clock::local_time()), *timeZone)), endDateTime(nullptr), totalPrice(0), vehicle(&pojazd), client(&klient), rentalLength(0)
{
    client -> addRent(this);
}

Rent::Rent(const Rent &r)
        :ID(r.ID), timeZone(new time_zone_ptr(*r.timeZone)), rentDateTime(new local_date_time(*r.rentDateTime)),
         endDateTime(new local_date_time(*r.endDateTime)), totalPrice(r.totalPrice), vehicle(new Vehicle(*r.vehicle)), client(new Client(*r.client)), rentalLength(r.rentalLength)
{
}

Rent&Rent:: operator= (const Rent& r)
{
    delete client;
    delete vehicle;
    delete timeZone;
    delete rentDateTime;
    delete endDateTime;
    client = new Client(*r.client);
    vehicle = new Vehicle(*r.vehicle);
    timeZone = new time_zone_ptr(*r.timeZone);
    rentDateTime = new local_date_time(*r.rentDateTime);
    endDateTime = new local_date_time(*r.endDateTime);
    ID = r.ID;
    totalPrice = r.totalPrice;
    rentalLength = r.rentalLength;
    return *this;
}

Rent::~Rent()
{
    rentDateTime = nullptr;
    endDateTime = nullptr;
    timeZone = nullptr;
    vehicle = nullptr;
    client = nullptr;
    delete rentDateTime;
    delete endDateTime;
    delete timeZone;
    delete vehicle;
    delete client;
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
    cout << vehicle->getRegistrationNumber()<<endl;
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


