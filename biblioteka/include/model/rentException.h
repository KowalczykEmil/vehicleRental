//
// Created by student on 19.06.2020.
//

#ifndef POBIPROJECT_RENTEXCEPTION_H
#define POBIPROJECT_RENTEXCEPTION_H
#include <stdexcept>

using namespace std;

class RentException : public logic_error
{
public:
    explicit RentException(const string&);
    static const string exceptionClientNullPtr;
    static const string exceptionVehicleNullPtr;
    static const string exceptionDays;
    static const string exceptionRentalPeriod;
};
#endif //POBIPROJECT_RENTEXCEPTION_H
