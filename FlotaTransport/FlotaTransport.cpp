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
    cout << "3. Stergere vehicul\n";
    cout << "4. Cauta vehicule dupa tip\n";
    cout << "5. Filtreaza vehicule dupa capacitate\n";
    cout << "6. Actualizare stare vehicul\n";
    cout << "7. Gaseste ruta intre 2 statii\n";
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

                int nrStatii;
                cout << "Numar statii pe ruta: ";
                cin >> nrStatii;

                vector<string> statii;
                for (int i = 0; i < nrStatii; i++) {
                    string s;
                    cout << "Statie " << i + 1 << ": ";
                    cin >> s;
                    statii.push_back(s);
                }

                Ruta ruta(statii);

                flota.adaugaVehicul(
                    make_shared<Autobuz>(id, marca, capacitate, linie, ruta)
                );

            }
            else if (tip == 2) {
                int nrStatii;
                cout << "Numar statii pe ruta: ";
                cin >> nrStatii;

                vector<string> statii;
                for (int i = 0; i < nrStatii; i++) {
                    string s;
                    cout << "Statie " << i + 1 << ": ";
                    cin >> s;
                    statii.push_back(s);
                }

                Ruta ruta(statii);

                flota.adaugaVehicul(
                    make_shared<Tren>(id, marca, capacitate, ruta)
                );
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
        else if (optiune == 3) {
            string id;
            cout << "Introdu ID vehicul de sters: ";
            cin >> id;

            if (flota.stergeVehicul(id))
                cout << "Vehicul sters cu succes.\n";
            else
                cout << "Vehiculul nu a fost gasit.\n";
        }
        else if (optiune == 4) {
            string tip;
            cout << "Introdu tipul vehiculului (Autobuz / Tren / Avion): ";
            cin >> tip;

            flota.cautaDupaTip(tip);
        }
         else if (optiune == 5)
            {
            int cap;
            cout << "Introdu capacitatea minima: ";
            cin >> cap;

            flota.filtreazaDupaCapacitate(cap);
             }
              else if (optiune == 6)
                 {
                     string id;
                     cout << "Introdu ID-ul vehiculului: ";
                     cin >> id;

                     flota.actualizeazaStareVehicul(id);
             
                 }
              else if (optiune == 7)
                  {
                      string start, stop;

                      cout << "Statie plecare: ";
                      cin >> start;

                      cout << "Statie destinatie: ";
                      cin >> stop;

                      flota.gasesteRuta(start, stop);

                  }

         


    } while (optiune != 0);

    cout << "Program incheiat.\n";
    return 0;
}
