#include <iostream>
#include <memory>
#include "Flota.h"
#include "Autobuz.h"
#include "Tren.h"
#include "Avion.h"

using namespace std;

int main() {
    cout << "=== Proiect: Flota de transport ===\n";

    Flota flota;

    // Adaugam vehicule folosind clasele derivate
    flota.adaugaVehicul(
        make_shared<Autobuz>("A01", "Mercedes", 50, 24)
    );

    flota.adaugaVehicul(
        make_shared<Tren>("T01", "Siemens", 300, "Bucuresti-Cluj")
    );

    flota.adaugaVehicul(
        make_shared<Avion>("V01", "Boeing", 180, "OTP", "JFK")
    );

    // Afisam flota
    flota.afiseazaFlota();

    cout << "\nNumar total de vehicule: "
        << flota.getNumarVehicule() << "\n";

    cout << "\nProgram incheiat.\n";
    return 0;
}
