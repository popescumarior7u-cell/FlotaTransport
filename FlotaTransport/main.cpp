#include <iostream>
#include "Flota.h"
#include "Autobuz.h"
#include "Tren.h"
#include "Avion.h"
using namespace std;

int main() {
    cout << "=== Proiect: Flota de transport ===\n";

    Flota flota;

    // Adaugam cateva vehicule manual
    Vehicul v1("A01", "Autobuz", "Mercedes", 50);
    Vehicul v2("T01", "Tren", "Siemens", 300);
    Vehicul v3("V01", "Avion", "Boeing", 180);

    flota.adaugaVehicul(v1);
    flota.adaugaVehicul(move(v2)); // Vom folosi contrusctorul de mutare
    flota.adaugaVehicul(v3);

    // Afisam flota
    flota.afiseazaFlota();

    cout << "\nNumar total de vehicule: " << flota.getNumarVehicule() << "\n";

    cout << "\nProgram incheiat.\n";
    return 0;
}
