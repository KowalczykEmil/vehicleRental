#include <iostream>
#include "../include/model/Client.hpp"

using namespace std;

main() {

    cout<<"Hello world!"<<endl;
    Client();
    Client Emil("Emil","Kowalczyk","9908110212");
    cout<<Emil.clientinfo()<<endl;

    return 0;
}
