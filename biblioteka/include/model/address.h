//
// Created by student on 15.06.2020.
//

#ifndef POBIPROJECT_ADDRESS_H
#define POBIPROJECT_ADDRESS_H
//#ifndef address
//#define address
#include <string>

using namespace std;

class Address
{
private:
    string street;
    int houseNumber;
public:
    Address(string, int);
    void setStreet(string newStreet);
    void setHouseNumber(int newHouseNumber);
    string getStreet();
    int getHouseNumber();
    string getAddress();
    void setAddress(string, int);
};

#endif //POBIPROJECT_ADDRESS_H
