//
// Created by student on 14.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/client.h"
#include "model/address.h"
#include "model/rent.h"
#include "model/car.h"
#include <boost/test/output_test_stream.hpp>

using boost::test_tools::output_test_stream;


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientFirstNameCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        BOOST_REQUIRE_EQUAL(client.getFirstName(), "Jan");
    }

    BOOST_AUTO_TEST_CASE(ClientLastNameCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        BOOST_REQUIRE_EQUAL(client.getLastName(), "Kowalski");
    }

    BOOST_AUTO_TEST_CASE(ClientPersonalIDCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        BOOST_CHECK_EQUAL(client.getPersonalID(), "1234567890");
    }

    BOOST_AUTO_TEST_CASE(ClientAddressCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        BOOST_CHECK_EQUAL(client.getAddress(), "adres 2");
    }

    BOOST_AUTO_TEST_CASE(ClientRegisteredAddressCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        BOOST_CHECK_EQUAL(client.getRegisteredAddress(), "adres2 5");
    }

    BOOST_AUTO_TEST_CASE(ClientSetNewAddressCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        Address NewAddress("new adres", 333);
        client.setAddress(NewAddress);
        BOOST_CHECK_EQUAL(client.getAddress(), "new adres 333");
    }

    BOOST_AUTO_TEST_CASE(ClientSetNewRegisteredAddressCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        Address NewAddress("new adres", 333);
        client.setRegisteredAddress(NewAddress);
        BOOST_CHECK_EQUAL(client.getRegisteredAddress(), "new adres 333");
    }

    BOOST_AUTO_TEST_CASE(ClientSetLastNameCase)
    {
        Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        client.setLastName("Duuuu");
        BOOST_CHECK_EQUAL(client.getLastName(), "Duuuu");
    }

    BOOST_AUTO_TEST_CASE(ClientAddRentCase)
    {
        output_test_stream output1;
        VehiclePtr v = make_shared<Car>(100, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        Rent wypozyczenie(client, v);
        Rent *r = &wypozyczenie;
        output1 << r->rentInfo()<<endl;
        BOOST_TEST(output1.is_equal(client->allRents()));
    }

BOOST_AUTO_TEST_SUITE_END()
