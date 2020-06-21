//
// Created by student on 19.06.2020.
//

#include "model/vehicleException.h"

VehicleException::VehicleException(const string& arg) : logic_error(arg)
{
}

const string VehicleException::exceptionRegistration = "INVALID REGISTRATION NUMBER";
const string VehicleException::exceptionPrice = "INVALID PRICE";


