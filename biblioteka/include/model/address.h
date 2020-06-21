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
    Address(const string&, const int&);
    string getAddress() const;
    void setAddress(const string&, const int&);
};

#endif //POBIPROJECT_ADDRESS_H
