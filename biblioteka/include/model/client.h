//
// Created by student on 26.04.2020.
//

#ifndef clientClass
#define clientClass
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;
class Rent;
class ClientType;
class Address;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<ClientType> ClientTypePtr;
typedef shared_ptr<Address> AddressPtr;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    AddressPtr address;
    AddressPtr registeredAddress;
    ClientTypePtr clientType;
    friend class ClientRepository;
    vector<RentPtr> archivedRents{};
    list<RentPtr> currentRents{};
    int balance;
public:
    Client(string, string, string, string, int, string, int);
    Client(const Client &c);
    string clientInfo();
    void setLastName(string newLastName);
    void setAddress(Address newAddress);
    void setRegisteredAddress(Address newAddress);
    string getFirstName();
    string getLastName();
    string getPersonalID();
    string getAddress();
    string getRegisteredAddress();
    void archiveRent(RentPtr);
    string allRents();
    string getFullName();
    void setClientType(ClientTypePtr);
    float getDiscount();
    int getVehicleLimit();
    int getNumberOfRents();
    void addCurrentRent(RentPtr);
    void removeArchiveRent(RentPtr);
    int getBalance();
    void setBalance(RentPtr);
    int getNumberOfArchRents();
    vector<RentPtr> getAllClientRents();
};
#endif

