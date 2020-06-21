//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTREPOSITORY_H
#define POBIPROJECT_CLIENTREPOSITORY_H
#include <list>
#include <string>
#include <memory>
//#include "model/repository.h"

using namespace std;
class Client;
class Rent;
class ClientType;
class ClientManager;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<ClientType> ClientTypePtr;

class ClientRepository
{
private:
    list<ClientPtr> allClients{};
    friend class ClientManager;
public:
    void addClient(ClientPtr);
    void removeClient(ClientPtr);
    void removeClient(unsigned int);
    void changeType(ClientPtr, ClientTypePtr);
    string clientRepositoryInfo();
    unsigned int getNumberOfClients();
};


#endif //POBIPROJECT_CLIENTREPOSITORY_H
