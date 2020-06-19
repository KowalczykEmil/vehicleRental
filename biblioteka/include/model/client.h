//
// Created by student on 26.04.2020.
//

#ifndef POBIPROJECT_CLIENT_HPP
#define POBIPROJECT_CLIENT_HPP
#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
    string firstName;
    string lastName;
    string address;
    string personalID;

public:
    Client();
    Client(string imie, string nazwisko, string id, string adres);
    ~Client();
    string clientInfo();
    void setLastName(string newLastName);
    void setAddress(string newAddress);
    string getFirstName();
    string getLastName();
    string getPersonalID();
    string getAddress();
};
#endif //POBIPROJECT_CLIENT_HPP



