//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/rent.h"
#include "model/client.h"
#include "model/vehicle.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentRentDataTimeCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        BOOST_REQUIRE_EQUAL(wypozyczenie.getPeriod(), 0);
    }

    BOOST_AUTO_TEST_CASE(RentEndDateTimeCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE(wypozyczenie.getRentalLength() > 0);
    }

    BOOST_AUTO_TEST_CASE(RentPeriodTimeCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE(wypozyczenie.getRentDate().local_time() <= wypozyczenie.getEndDate().local_time());
    }

    BOOST_AUTO_TEST_CASE(RentValueCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getPrice(), wypozyczenie.getRentalLength() * pojazd -> getPrice());
    }

    BOOST_AUTO_TEST_CASE(RentClientCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        BOOST_REQUIRE_EQUAL(wypozyczenie.getClient(), "123");
    }

    BOOST_AUTO_TEST_CASE(RentEndClientCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getClient(), "123");
    }


BOOST_AUTO_TEST_SUITE_END()
