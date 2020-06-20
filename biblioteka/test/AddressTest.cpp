//
// Created by student on 19.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/client.h"
#include "model/address.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(AddressGetAddressCase)
    {
        Address adres("street1", 10);
        BOOST_REQUIRE_EQUAL(adres.getAddress(), "street1 10");
    }

    BOOST_AUTO_TEST_CASE(AddressSetAddressCase)
    {
        Address adres("street1", 10);
        adres.setAddress("street2", 1);
        BOOST_REQUIRE_EQUAL(adres.getAddress(), "street2 1");
    }

    BOOST_AUTO_TEST_CASE(AddressClientCompositionCase)
    {
        Address adres("street1", 10);
        Client klient1("Emil", "Kowalczyk", "12345", adres.getStreet(), adres.getHouseNumber(), adres.getStreet(), adres.getHouseNumber());
        Client klient2("Dominik", "Swiader", "125", adres.getStreet(), adres.getHouseNumber(), adres.getStreet(), adres.getHouseNumber());
        adres.setAddress("street2", 1);
        BOOST_REQUIRE_EQUAL(klient1.getAddress(), klient2.getAddress());
    }

BOOST_AUTO_TEST_SUITE_END()
