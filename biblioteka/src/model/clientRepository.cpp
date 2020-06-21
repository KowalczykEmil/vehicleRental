//
// Created by student on 19.06.2020.
//
#include "model/clientRepository.h"
#include <sstream>
#include "model/clientType.h"
#include "model/client.h"
#include "model/clientRepositoryException.h"
#include <algorithm>

using namespace std;

void ClientRepository::addClient(ClientPtr client)
{
    if (client == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    for(const auto &c : allClients)
    {
        if(client -> getPersonalID() == c -> getPersonalID())
        {
            throw ClientRepositoryException(ClientRepositoryException::exceptionClientExist);
        }
    }
    allClients.push_back(client);
}

void ClientRepository::removeClient(ClientPtr client)
{
    if (client == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    bool found = (find(allClients.begin(), allClients.end(), client) != allClients.end());
    if (!found) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    allClients.remove(client);
}

void ClientRepository::removeClient(unsigned int i)
{
    unsigned int counter = 1;
    if (i > allClients.size()) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    for (auto& client : allClients)
    {
        if(counter == i)
        {
            allClients.remove(client);
            break;
        }
    }
}

void ClientRepository::changeType(ClientPtr clientToChange, ClientTypePtr newType)
{
    if (clientToChange == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    (*clientToChange).setClientType(newType);
}

string ClientRepository::clientRepositoryInfo()
{
    ostringstream chain;
    unsigned int i = 1;
    for (const auto& client : allClients)
    {
        chain << i << ". " << client->getFullName();
        if (client->clientType != nullptr)
        {
            chain << " [" << client->clientType->getType() << "]" << endl;
        }
        else
        {
            chain << endl;
        }
        i ++;
    }
    return chain.str();
}

unsigned int ClientRepository::getNumberOfClients()
{
    return allClients.size();
}

