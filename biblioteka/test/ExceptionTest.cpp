//
// Created by student on 19.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/rent.h"
#include "model/client.h"
#include "model/vehicle.h"
#include "model/address.h"
#include "model/rentsRepository.h"
#include "model/clientRepository.h"
#include "model/vehicleRepository.h"
#include "model/rentsManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentNullPtrExceptionCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        BOOST_REQUIRE_THROW(RentPtr wypozyczenie = make_shared<Rent>(client, nullptr, 10), logic_error);
        BOOST_REQUIRE_THROW(RentPtr wypozyczenie = make_shared<Rent>(nullptr, pojazd, 10), logic_error);
    }

    BOOST_AUTO_TEST_CASE(RentSameUIDExceptionCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        RentPtr wypozyczenie = make_shared<Rent>(client, pojazd, 10);
        RentsManager m;
        m.rentVehicle(wypozyczenie);
        BOOST_REQUIRE_THROW(m.rentVehicle(wypozyczenie), logic_error);
    }
    BOOST_AUTO_TEST_CASE(ClientSameIDExceptionCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client2 = make_shared<Client>("Em2l", "Kowks", "123", "Zwolinskiego", 8, "Lowicka", 13);
        ClientRepository r;
        r.create(client);
        BOOST_REQUIRE_THROW(r.create(client2), logic_error);
    }

    BOOST_AUTO_TEST_CASE(VehicleSameRegExceptionCase)
    {
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        VehiclePtr pojazd2 = make_shared<Vehicle>(10210.2, "5Y80");
        VehicleRepository v;
        v.create(pojazd);
        BOOST_REQUIRE_THROW(v.create(pojazd2), logic_error);
    }

    BOOST_AUTO_TEST_CASE(AddressExceptionCase)
    {
        BOOST_REQUIRE_THROW(Address("", 1), logic_error);
        BOOST_REQUIRE_THROW(Address("sss", -1), logic_error);
    }

    BOOST_AUTO_TEST_CASE(ClientExceptionCase)
    {
        BOOST_REQUIRE_THROW(Client("", "aaa", "aaa", "aa", 3, "ss", 4), logic_error);
        BOOST_REQUIRE_THROW(Client("a", "", "aaa", "aa", 3, "ss", 4), logic_error);
        BOOST_REQUIRE_THROW(Client("aaa", "aaa", "", "aa", 3, "ss", 4), logic_error);
        BOOST_REQUIRE_THROW(Client("s", "aaa", "aaa", "", 3, "ss", 4), logic_error);
        BOOST_REQUIRE_THROW(Client("a", "aaa", "aaa", "aa", 3, "", 4), logic_error);
        BOOST_REQUIRE_THROW(Client("aa", "aaa", "aaa", "aa", -3, "ss", 4), logic_error);
        BOOST_REQUIRE_THROW(Client("", "aaa", "aaa", "aa", 3, "ss", -4), logic_error);
    }
    BOOST_AUTO_TEST_CASE(ClientDifferentIDCase)
    {
        ClientPtr client1 = make_shared<Client>("Emil", "Kowalczyk", "1234", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client2 = make_shared<Client>("Emil", "Kowalczyk", "1235", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client3 = make_shared<Client>("Emil", "Kowalczyk", "1236", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client4 = make_shared<Client>("Emil", "Kowalczyk", "1237", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client5 = make_shared<Client>("Emil", "Kowalczyk", "1238", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client6 = make_shared<Client>("Emil", "Kowalczyk", "1239", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client7 = make_shared<Client>("Emil", "Kowalczyk", "1230", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client8 = make_shared<Client>("Emil", "Kowalczyk", "1243", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client9 = make_shared<Client>("Emil", "Kowalczyk", "1123", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr client10 = make_shared<Client>("Emil", "Kowalczyk", "1253", "Zwolinskiego", 8, "Lowicka", 13);
        ClientPtr tablica[10];
        tablica[0] = client1;
        tablica[1] = client2;
        tablica[2] = client3;
        tablica[3] = client4;
        tablica[4] = client5;
        tablica[5] = client6;
        tablica[6] = client7;
        tablica[7] = client8;
        tablica[8] = client9;
        tablica[9] = client10;
        ClientRepository repozytorium;
        for(const auto& client : tablica)
        {
            repozytorium.create(client);
        }
        BOOST_REQUIRE_EQUAL(repozytorium.getRepository().size(), 10);
    }


BOOST_AUTO_TEST_SUITE_END()

