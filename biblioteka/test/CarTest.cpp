//
// Created by student on 19.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/car.h"
#include <string>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CarPriceCase)
    {
        Car SkodaSuperb(1000, "GD 22101", 2000, 'C');
        float eps = 0.001;
        BOOST_TEST(abs(SkodaSuperb.getPrice() - 1800) <= eps);
    }

    BOOST_AUTO_TEST_CASE(CarRegistrationNumberCase)
    {
        Car SkodaSuperb(1000, "GD 22101", 2000, 'C');
        BOOST_REQUIRE_EQUAL(SkodaSuperb.getRegistrationNumber(), "GD 22101");
    }

    BOOST_AUTO_TEST_CASE(CarEngineDisplacementCase)
    {
        Car SkodaSuperb(1000, "GD 22101", 2000, 'C');
        BOOST_REQUIRE_EQUAL(SkodaSuperb.getEngineDisplacement(), 2000);
    }

    BOOST_AUTO_TEST_CASE(CarVehicleInfoCase)
    {
        string chain;
        Car SkodaSuperb(1000, "GD 22101", 2000, 'C');
        chain = "CAR: Registration number :" + SkodaSuperb.getRegistrationNumber() + ". Engine displacement: " + to_string(SkodaSuperb.getEngineDisplacement()) + ". Price: " + to_string(SkodaSuperb.getPrice()) + ". Car class: C";
        BOOST_REQUIRE_EQUAL(SkodaSuperb.vehicleInfo(), chain);
    }



BOOST_AUTO_TEST_SUITE_END()

