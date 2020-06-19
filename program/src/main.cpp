#include <iostream>
#include "model/client.h"

using namespace std;

int main() {
    Client klient1, klient2("Emil", "Kowalczyk", "230178","adres1");
    Client *klient3 = new Client("Dominik", "Swiader", "230214","adres2");
    cout << klient1.clientInfo() << endl;
    cout << klient2.clientInfo() << endl;
    cout << (*klient3).clientInfo() << endl;
    Client klient4("", "", "", "");
    cout << klient4.clientInfo() << endl;
    //klient1.firstName = "Andrzej";
    delete klient3;
    return 0;
}