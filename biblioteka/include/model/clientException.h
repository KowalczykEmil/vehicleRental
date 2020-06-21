//
// Created by student on 19.06.2020.
//
#ifndef POBIPROJECT_CLIENTEXCEPTION_H
#define POBIPROJECT_CLIENTEXCEPTION_H
#include <stdexcept>

using namespace std;

class ClientException : public logic_error
{
public:
    explicit ClientException(const string&);
    static const string exceptionFirstName;
    static const string exceptionLastName;
    static const string exceptionPersonalID;
    static const string exceptionAddress;
    static const string exceptionRegisteredAddress;
};

#endif //POBIPROJECT_CLIENTEXCEPTION_H
