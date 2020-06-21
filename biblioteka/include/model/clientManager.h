//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTMENAGER_H
#define POBIPROJECT_CLIENTMENAGER_H
#include <memory>
#include <vector>
#include <string>

using namespace std;
class Client;
class ClientRepository;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<ClientRepository> ClientRepoPtr;

class ClientManager{
    ClientRepoPtr currentClients;
    ClientRepoPtr archiveClients;
public:
    ClientManager();
    void addClient(ClientPtr);
    void removeClient(ClientPtr);
    int getNumberOfArchClients();
    int getNumberOfCurrentClients();
};

#endif //POBIPROJECT_CLIENTMENAGER_H
