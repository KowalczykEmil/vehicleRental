//
// Created by student on 19.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/vehicleRepository.h"
#include "model/bicycle.h"
#include "model/car.h"
#include "model/moped.h"
#include <sstream>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRaportCase)
    {
        VehiclePtr tablica[10];
        tablica[0] = make_shared<Bicycle>(110, "AB321");
        tablica[1] = make_shared<Bicycle>(120, "BG456");
        tablica[2] = make_shared<Car>(560, "ERW 52112", 1300, 'A');
        tablica[3] = make_shared<Car>(700, "CW 53351", 1600, 'B');
        tablica[4] = make_shared<Car>(1000, "GD 22101", 2000, 'C');
        tablica[5] = make_shared<Car>(1500, "WN 8883H", 2400, 'E');
        tablica[6] = make_shared<Moped>(300, "WPR 723i", 800);
        tablica[7] = make_shared<Moped>(400, "WN", 1100);
        tablica[8] = make_shared<Moped>(150, "DT 231", 700);
        tablica[9] = make_shared<Moped>(130, "DG 32V", 500);
        VehicleRepository repozytorium;
        ostringstream chain;
        for(unsigned int i = 0; i<10; i++)
        {
            repozytorium.create(tablica[i]);
            chain << i+1 << "- " << tablica[i]->vehicleInfo()<<endl;
        }
        BOOST_REQUIRE_EQUAL(repozytorium.getAll(), chain.str());
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetVehicleCase)
    {
        VehiclePtr tablica[10];
        tablica[0] = make_shared<Bicycle>(110, "AB321");
        tablica[1] = make_shared<Bicycle>(120, "BG456");
        tablica[2] = make_shared<Car>(560, "ERW 52112", 1300, 'A');
        tablica[3] = make_shared<Car>(700, "CW 53351", 1600, 'B');
        tablica[4] = make_shared<Car>(1000, "GD 22101", 2000, 'C');
        tablica[5] = make_shared<Car>(1500, "WN 8883H", 2400, 'E');
        tablica[6] = make_shared<Moped>(300, "WPR 723i", 800);
        tablica[7] = make_shared<Moped>(400, "WN", 1100);
        tablica[8] = make_shared<Moped>(150, "DT 231", 700);
        tablica[9] = make_shared<Moped>(130, "DG 32V", 500);
        VehicleRepository repozytorium;
        ostringstream chain;
        for(unsigned int i = 0; i<10; i++)
        {
            repozytorium.create(tablica[i]);
            if(i==3)
            {
                chain << tablica[i]->vehicleInfo();
            }
        }
        BOOST_REQUIRE_EQUAL(repozytorium.search(4), tablica[3]);
    }


BOOST_AUTO_TEST_SUITE_END()

