//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_RENTSMENAGER_H
#define POBIPROJECT_RENTSMENAGER_H
#include <memory>
#include <vector>
#include <string>

using namespace std;
class RentsRepository;
class Rent;
class Client;
class ClientRepository;
class Vehicle;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<ClientRepository> ClientRepoPtr;
typedef shared_ptr<Vehicle> VehiclePtr;

class RentsManager{
    shared_ptr<RentsRepository> currentRents;
    shared_ptr<RentsRepository> archiveRents;
    ClientRepoPtr clientRepository;
public:
    RentsManager();
    void returnVehicle(RentPtr);
    void rentVehicle(RentPtr);
    vector<RentPtr> getAllClientRents(ClientPtr);
    string getClientForRentedVehicle(VehiclePtr);
    int getNumberOfCurrentRents();
    int getNumberOfArchRents();
    void changeClientType(ClientPtr);
    int checkClientRentBalance(ClientPtr);
};

#endif //POBIPROJECT_RENTSMENAGER_H
