//
// Created by student on 20.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/moped.h"
#include <string>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(MopedPriceCase)
    {
        Moped Suzuki(130, "DG 32V", 500);
        float eps = 0.001;
        BOOST_TEST(abs(Suzuki.getPrice() - 130) <= eps);
    }

    BOOST_AUTO_TEST_CASE(MopedRegistrationNumberCase)
    {
        Moped Suzuki(130, "DG 32V", 500);
        BOOST_REQUIRE_EQUAL(Suzuki.getRegistrationNumber(), "DG 32V");
    }

    BOOST_AUTO_TEST_CASE(MopedEngineDisplacementCase) {
        Moped Suzuki(130, "DG 32V", 500);
        BOOST_REQUIRE_EQUAL(Suzuki.getEngineDisplacement(), 500);
    }

    BOOST_AUTO_TEST_CASE(MopedVehicleInfoCase) {
        string chain;
        Moped Suzuki(130, "DG 32V", 500);;
        chain = "MOPED: Registration number :" + Suzuki.getRegistrationNumber() + ". Engine displacement: " + to_string(Suzuki.getEngineDisplacement()) + ". Price: " + to_string(Suzuki.getPrice());
        BOOST_REQUIRE_EQUAL(Suzuki.vehicleInfo(), chain);
    }



BOOST_AUTO_TEST_SUITE_END()

