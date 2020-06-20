//
// Created by student on 26.04.2020.
//

#ifndef clientClass
#define clientClass
#include <string>
#include "model/address.h"
#include <vector>
#include "model/rent.h"
#include <memory>


using namespace std;


class Rent;
typedef unique_ptr<Address> AddressPtr;


class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    AddressPtr address;
    AddressPtr registeredAddress;
    vector<Rent *> rentVector{};
public:
    Client(string imie, string nazwisko, string id, string ulica, int nrDomu, string ulica2, int nrDomu2);
    Client(const Client &c);
    ~Client();
    string clientInfo();
    void setLastName(string newLastName);
    void setAddress(Address newAddress);
    void setRegisteredAddress(Address newAddress);
    string getFirstName();
    string getLastName();
    string getPersonalID();
    string getAddress();
    string getRegisteredAddress();
    void addRent(Rent *);
    string allRents();
    string getFullName();
};

typedef shared_ptr<Client> ClientPtr;
#endif

