//
// Created by student on 19.06.2020.
//
#include "model/addressException.h"

AddressException::AddressException(const string& arg) : logic_error(arg)
{}

const string AddressException::exceptionStreet = "INVALID STREET NAME";
const string AddressException::exceptionHouseNumber = "INVALID HOUSE NUMBER";

