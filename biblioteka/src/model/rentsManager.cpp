//
// Created by student on 19.06.2020.
//
#include "model/rentsManager.h"
#include "model/clientGold.h"
#include "model/clientBronze.h"
#include "model/clientSilver.h"
#include "model/rent.h"
#include "model/clientRepository.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/rentsRepository.h"
#include "model/rentsRepositoryException.h"


RentsManager::RentsManager()
        : currentRents(new RentsRepository), archiveRents(new RentsRepository), clientRepository(new ClientRepository)
{
}

void RentsManager::rentVehicle(RentPtr r)
{
    bool found = (find(currentRents -> rentRepositoryList.begin(), currentRents -> rentRepositoryList.end(), r) != currentRents -> rentRepositoryList.end());
    if (found) throw RentsRepositoryException(RentsRepositoryException::exceptionVehicleRented);
    bool isRented = false;
    for(const auto& rent : currentRents->rentRepositoryList)
    {
        if(r->vehicle->getRegistrationNumber() == rent->vehicle->getRegistrationNumber())
        {
            isRented = true;
            break;
        }
    }
    if(!isRented and r -> client -> getNumberOfRents() < r -> client -> getVehicleLimit())
    {
        currentRents -> createRent(r);
        r -> client -> addCurrentRent(r);
    }
    else
    {
        if(!isRented)
        {
            throw RentsRepositoryException(RentsRepositoryException::exceptionLimitExceeded);
        }
        else
        {
            throw RentsRepositoryException(RentsRepositoryException::exceptionVehicleRented);
        }
    }
}

void RentsManager::returnVehicle(RentPtr r)
{
    r -> client -> removeArchiveRent(r);
    r -> endRent();
    currentRents -> removeRent(r);
    archiveRents -> createRent(r);
    changeClientType(r -> client);
}

string RentsManager::getClientForRentedVehicle(shared_ptr<Vehicle> v)
{
    string clientInfo;
    for(const auto& rent : currentRents->rentRepositoryList)
    {
        if(rent->vehicle == v)
        {
            clientInfo = rent->client->clientInfo();
            break;
        }
    }
    return clientInfo;
}

int RentsManager::getNumberOfCurrentRents()
{
    return currentRents -> rentRepositoryList.size();
}

int RentsManager::getNumberOfArchRents()
{
    return archiveRents -> rentRepositoryList.size();
}

void RentsManager::changeClientType(ClientPtr client)
{
    if(client -> getDiscount() != 0.3)
    {
        int b = checkClientRentBalance(client);
        if (b >= 1000 and b < 3000)
        {
            ClientTypePtr bronze = make_shared<ClientBronze>();
            clientRepository -> changeType(client, bronze);
        }
        else if (b >= 3000 and b < 10000)
        {
            ClientTypePtr silver = make_shared<ClientSilver>();
            clientRepository -> changeType(client, silver);
        }
        else if (b >= 10000)
        {
            ClientTypePtr gold = make_shared<ClientGold>();
            clientRepository -> changeType(client, gold);
        }
    }
}

int RentsManager::checkClientRentBalance(ClientPtr client)
{
    return client -> getBalance();
}

vector<RentPtr> RentsManager::getAllClientRents(ClientPtr client)
{
    return client -> getAllClientRents();
}

