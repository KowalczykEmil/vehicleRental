//
// Created by student on 15.06.2020.
//

#ifndef POBIPROJECT_ADDRESS_H
#define POBIPROJECT_ADDRESS_H
//#ifndef address
//#define address
#include <string>
#include <iostream>

using namespace std;

class Address
{
private:
    string street;
    int houseNumber;
public:
    Address(string ulica, int numerDomu);
    ~Address();
    void setStreet(string newStreet);
    void setHouseNumber(int newHouseNumber);
    string getStreet();
    int getHouseNumber();
};

#endif //POBIPROJECT_ADDRESS_H
