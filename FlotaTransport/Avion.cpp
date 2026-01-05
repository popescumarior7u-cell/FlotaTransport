#include "Avion.h"
#include <iostream>
using namespace std;

Avion::Avion(string id, string marca, int capacitate,
    string aeroportPlecare, string aeroportDestinatie)
    : Vehicul(id, "Avion", marca, capacitate),
    aeroportPlecare(aeroportPlecare),
    aeroportDestinatie(aeroportDestinatie) {
}

void Avion::afiseaza() const {
    cout << "[Avion] ";
    Vehicul::afiseaza();
    cout << " Plecare: " << aeroportPlecare
        << " Destinatie: " << aeroportDestinatie << "\n";
}
