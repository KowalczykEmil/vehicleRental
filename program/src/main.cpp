#include <iostream>
#include "model/client.h"
#include "model/vehicle.h"
#include "model/bicycle.h"
#include "model/car.h"
#include "model/moped.h"
#include "model/vehicleRepository.h"


using namespace std;
int main() {
    VehiclePtr Scott = make_shared<Bicycle>(110, "AB321");
    Bicycle Giant(120, "BG456");
    Car OpelAstra(560, "ERW 52112", 1300, 'A');
    Car OpelZafira(700, "CW 53351", 1600, 'B');
    Car SkodaSuperb(1000, "GD 22101", 2000, 'C');
    Car BMWM3(1500, "WN 8883H", 2400, 'E');
    Moped Yamaha(300, "WPR 723i", 800);
    Moped Cross(400, "WN", 1100);
    Moped Aprilla(150, "DT 231", 700);
    Moped Suzuki(130, "DG 32V", 500);
    ClientPtr klient = make_shared<Client>("Emil", "Kowalczyk", "1234", "a", 2, "b", 3);
    Rent wypozyczenie(klient, Scott);
    int a;
    cin >> a;
    wypozyczenie.endRent();
    cout << wypozyczenie.rentInfo();
    return 0;
}