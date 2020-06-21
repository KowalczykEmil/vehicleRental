//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTSILVER_H
#define POBIPROJECT_CLIENTSILVER_H
#include "model/clientType.h"

class ClientSilver : public ClientType
{
public:
    float discount() override;
    int vehicleLimit() override;
    string getType() override;
};
#endif //POBIPROJECT_CLIENTSILVER_H
