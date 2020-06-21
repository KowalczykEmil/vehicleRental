//
// Created by student on 19.06.2020.
//
#include "model/clientManager.h"
#include "model/clientGold.h"
#include "model/rent.h"
#include "model/clientRepository.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/clientRepositoryException.h"


ClientManager::ClientManager()
        : currentClients(new ClientRepository), archiveClients(new ClientRepository)
{
}

void ClientManager::addClient(ClientPtr client)
{
    bool exists = false;
    bool archived = false;
    for(const auto& c : currentClients->allClients)
    {
        if(client->getPersonalID() == c->getPersonalID())
        {
            exists = true;
            break;
        }
    }
    for(const auto& c : archiveClients->allClients)
    {
        if(client->getPersonalID() == c->getPersonalID())
        {
            archived = true;
            break;
        }
    }
    if(exists)
    {
        throw ClientRepositoryException(ClientRepositoryException::exceptionClientExist);
    }
    else
    {
        if(archived)
        {
            archiveClients -> removeClient(client);
        }
        currentClients -> addClient(client);
    }
}

void ClientManager::removeClient(ClientPtr client)
{
    currentClients -> removeClient(client);
    archiveClients -> addClient(client);
}

int ClientManager::getNumberOfCurrentClients()
{
    return currentClients -> allClients.size();
}

int ClientManager::getNumberOfArchClients()
{
    return archiveClients -> allClients.size();
}


