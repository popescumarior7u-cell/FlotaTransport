#include "Autobuz.h"
#include <iostream>
using namespace std;

Autobuz::Autobuz(string id, string marca, int capacitate, int linie)
    : Vehicul(id, "Autobuz", marca, capacitate), linie(linie) {
}

void Autobuz::afiseaza() const {
    cout << "[Autobuz] ";
    Vehicul::afiseaza();
    cout << " Linie: " << linie << "\n";
}
