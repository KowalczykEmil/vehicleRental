//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTGOLD_H
#define POBIPROJECT_CLIENTGOLD_H
#include "model/clientType.h"

class ClientGold : public ClientType
{
public:
    float discount() override;
    int vehicleLimit() override;
    string getType() override;
};

#endif //POBIPROJECT_CLIENTGOLD_H
