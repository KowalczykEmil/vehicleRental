//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_CLIENTBRONZE_H
#define POBIPROJECT_CLIENTBRONZE_H
#include "model/clientType.h"

class ClientBronze : public ClientType
{
public:
    float discount() override;
    int vehicleLimit() override;
    string getType() override;
};
#endif //POBIPROJECT_CLIENTBRONZE_H
