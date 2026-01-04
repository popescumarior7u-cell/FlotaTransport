#include "Avion.h"
#include <iostream>
using namespace std;

Avion::Avion(string id, string marca, int capacitate, string aeroportDestinatie)
    : Vehicul(id, "Avion", marca, capacitate), aeroportDestinatie(aeroportDestinatie) {
}

void Avion::afiseaza() const {
    cout << "[Avion] ";
    Vehicul::afiseaza();
    cout << " Aeroport destinatie: " << aeroportDestinatie << "\n";
}
