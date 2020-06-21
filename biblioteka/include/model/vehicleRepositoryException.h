//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORYEXCEPTION_H
#define POBIPROJECT_VEHICLEREPOSITORYEXCEPTION_H
#include <stdexcept>

using namespace std;

class VehicleRepositoryException : public logic_error
{
public:
    explicit VehicleRepositoryException(const string&);
    static const string exceptionVehicleNotFound;
    static const string exceptionVehicleNullPtr;
    static const string exceptionVehicleExists;
};

#endif //POBIPROJECT_VEHICLEREPOSITORYEXCEPTION_H
