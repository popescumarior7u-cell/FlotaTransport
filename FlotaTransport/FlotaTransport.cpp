#include <iostream>
#include <memory>
#include "Flota.h"
#include "Autobuz.h"
#include "Tren.h"
#include "Avion.h"

using namespace std;

void afiseazaMeniu() {
    cout << "\n=== MENIU FLOTA TRANSPORT ===\n";
    cout << "1. Adauga vehicul\n";
    cout << "2. Afiseaza flota\n";
    cout << "0. Iesire\n";
    cout << "Alege optiunea: ";
}

int main() {
    Flota flota;
    int optiune;

    do {
        afiseazaMeniu();
        cin >> optiune;

        if (optiune == 1) {
            int tip;
            cout << "\nTip vehicul:\n";
            cout << "1. Autobuz\n";
            cout << "2. Tren\n";
            cout << "3. Avion\n";
            cout << "Alege: ";
            cin >> tip;

            string id, marca;
            int capacitate;

            cout << "ID: ";
            cin >> id;
            cout << "Marca: ";
            cin >> marca;
            cout << "Capacitate: ";
            cin >> capacitate;

            if (tip == 1) {
                int linie;
                cout << "Linie autobuz: ";
                cin >> linie;

                flota.adaugaVehicul(make_shared<Autobuz>(id, marca, capacitate, linie));
            }
            else if (tip == 2) {
                string ruta;
                cout << "Ruta tren: ";
                cin.ignore();
                getline(cin, ruta);

                flota.adaugaVehicul(make_shared<Tren>(id, marca, capacitate, ruta));
            }
            else if (tip == 3) {
                string plecare, destinatie;
                cout << "Aeroport plecare: ";
                cin >> plecare;
                cout << "Aeroport destinatie: ";
                cin >> destinatie;

                flota.adaugaVehicul(
                    make_shared<Avion>(id, marca, capacitate, plecare, destinatie)
                );
            }
        }
        else if (optiune == 2) {
            flota.afiseazaFlota();
            cout << "Numar total vehicule: " << flota.getNumarVehicule() << "\n";
        }

    } while (optiune != 0);

    cout << "Program incheiat.\n";
    return 0;
}
