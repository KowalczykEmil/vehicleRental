//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTREPOSITORYEXCEPTION_H
#define POBIPROJECT_CLIENTREPOSITORYEXCEPTION_H
#include <stdexcept>

using namespace std;

class ClientRepositoryException : public logic_error
{
public:
    explicit ClientRepositoryException(const string&);
    static const string exceptionClientNotExist;
    static const string exceptionClientNullPtr;
    static const string exceptionClientExist;
};
#endif //POBIPROJECT_CLIENTREPOSITORYEXCEPTION_H
