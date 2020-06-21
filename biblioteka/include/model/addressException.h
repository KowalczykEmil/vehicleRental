//
// Created by student on 19.06.2020.
//
#ifndef POBIPROJECT_ADDRESSEXCEPTION_H
#define POBIPROJECT_ADDRESSEXCEPTION_H
#include <stdexcept>

using namespace std;

class AddressException : public logic_error
{
public:
    explicit AddressException(const string&);
    static const string exceptionStreet;
    static const string exceptionHouseNumber;
};

#endif //POBIPROJECT_ADDRESSEXCEPTION_H
