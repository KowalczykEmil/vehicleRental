//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTTYPE_H
#define POBIPROJECT_CLIENTTYPE_H
#include <string>

using namespace std;

class ClientType
{
public:
    virtual float discount()=0;
    virtual int vehicleLimit()=0;
    virtual ~ClientType()= default;
    virtual string getType()=0;
};
#endif //POBIPROJECT_CLIENTTYPE_H
