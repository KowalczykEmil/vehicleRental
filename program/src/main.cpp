#include <iostream>
#include "../include/model/Client.hpp"

using namespace std;

main() {

    cout<<"Hello world!"<<endl;
    Client E1("Emil","Kowalczyk","9908110212");
    Client D2;
    cout<<E1.clientinfo()<<endl;
    cout<<D2.clientinfo()<<endl;
    E1.setFirstName("Andrzej");
    D2.setFirstName("Dominik");
    D2.setLastName("Świąder");
    D2.setPersonalId("97031201771");
    cout<<E1.clientinfo()<<endl;
    cout<<D2.clientinfo()<<endl;

    return 0;
}
