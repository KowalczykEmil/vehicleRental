#include <iostream>
#include "model/client.h"
#include "model/clientType.h"
#include "model/clientRepository.h"
#include "model/clientGold.h"

using namespace std;

int main() {
    ClientPtr klient = make_shared<Client>("Emil", "Kowalczyk", "12345", "a", 2, "b", 3);
    cout << (*klient).getDiscount();
    cout << (*klient).getVehicleLimit();
    ClientTypePtr typeOfClient(new ClientGold);
    (*klient).setClientType(typeOfClient);
    cout << (*klient).getDiscount();
     cout << (*klient).getVehicleLimit();
    ClientRepository repo;
    repo.create(klient);
    cout << endl;
    cout << endl;
    ClientPtr klient2 = make_shared<Client>("Wlodzimierz", "Kowalczyk", "12334", "a", 2, "b", 3);
    ClientPtr klient3 = make_shared<Client>("Justyna", "Kowalczyk", "12w34", "a", 2, "b", 3);
    ClientPtr klient4 = make_shared<Client>("Stanislawa", "Swiader", "12134", "a", 2, "b", 3);
    repo.create(klient2);
    repo.create(klient3);
    repo.create(klient4);
    cout << repo.getAll() << endl;
    repo.changeType(klient2, typeOfClient);
    cout << repo.getAll() << endl;
    repo.remove(klient3);
    cout << repo.getAll() << endl;
}