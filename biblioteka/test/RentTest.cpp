//
// Created by student on 16.06.2020.
//
#include <boost/test/unit_test.hpp>

#include "model/rent.h"
#include "model/client.h"
#include "model/vehicle.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentRentDataTimeCase) {
        Client klient("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        Vehicle pojazd(1010.2, "5Y80");
        Rent wypozyczenie(klient, pojazd);
        klient.allRents();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getPeriod(), 0);
    }

    BOOST_AUTO_TEST_CASE(RentEndDateTimeCase) {
        Client klient("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        Vehicle pojazd(1010.2, "5Y80");
        Rent wypozyczenie(klient, pojazd);
        klient.allRents();
        wypozyczenie.endRent();
        wypozyczenie.rentInfo();
        klient.allRents();
        klient.clientInfo();
        BOOST_REQUIRE(wypozyczenie.getRentalLength() > 0);
    }

    BOOST_AUTO_TEST_CASE(RentPeriodTimeCase) {
        Client klient("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        Vehicle pojazd(1010.2, "5Y80");
        Rent wypozyczenie(klient, pojazd);
        klient.allRents();
        wypozyczenie.endRent();
        wypozyczenie.rentInfo();
        klient.allRents();
        klient.clientInfo();
        BOOST_REQUIRE(wypozyczenie.getRentDate().local_time() <= wypozyczenie.getEndDate().local_time());
    }

    BOOST_AUTO_TEST_CASE(RentValueCase) {
        Client klient("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        Vehicle pojazd(1010.2, "5Y80");
        Rent wypozyczenie(klient, pojazd);
        klient.allRents();
        wypozyczenie.endRent();
        wypozyczenie.rentInfo();
        klient.allRents();
        klient.clientInfo();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getPrice(), wypozyczenie.getRentalLength() * pojazd.getPrice());
    }

BOOST_AUTO_TEST_SUITE_END()