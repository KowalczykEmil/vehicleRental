#include <iostream>
#include "model/client.h"
#include "model/vehicle.h"
#include "model/bicycle.h"
#include "model/car.h"
#include "model/moped.h"
#include "model/vehicleRepository.h"


using namespace std;
int main() {
    Vehicle *tablica[10];
    Bicycle Scott(110, "AB321");
    Bicycle Giant(120, "BG456");
    Car OpelAstra(560, "ERW 52112", 1300, 'A');
    Car OpelZafira(700, "CW 53351", 1600, 'B');
    Car SkodaSuperb(1000, "GD 22101", 2000, 'C');
    Car BMWM3(1500, "WN 8883H", 2400, 'E');
    Moped Yamaha(300, "WPR 723i", 800);
    Moped Cross(400, "WN", 1100);
    Moped Aprilla(150, "DT 231", 700);
    Moped Suzuki(130, "DG 32V", 500);
    tablica[0] = &Scott;
    tablica[1] = &Giant;
    tablica[2] = &OpelAstra;
    tablica[3] = &OpelZafira;
    tablica[4] = &SkodaSuperb;
    tablica[5] = &BMWM3;
    tablica[6] = &Yamaha;
    tablica[7] = &Cross;
    tablica[8] = &Aprilla;
    tablica[9] = &Suzuki;
    Vehicle *vehicle;
    VehicleRepository repozytorium;
    for(unsigned int i = 0; i<10; i++)
    {
        vehicle = tablica[i];
        repozytorium.addVehicle(vehicle);
    }

    repozytorium.vehicleRaport();
    unsigned int index = 6;

    cout<<endl<<"Choosen vehicle of index "<<index<<" is:  "<<endl;
    repozytorium.getVehicle(index);
    return 0;
}