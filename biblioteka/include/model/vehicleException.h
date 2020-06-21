//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_VEHICLEEXCEPTION_H
#define POBIPROJECT_VEHICLEEXCEPTION_H
#include <stdexcept>

using namespace std;

class VehicleException : public logic_error
{
public:
    explicit VehicleException(const string&);
    static const string exceptionPrice;
    static const string exceptionRegistration;
};
#endif //POBIPROJECT_VEHICLEEXCEPTION_H
