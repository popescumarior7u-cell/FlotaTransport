#include "Autobuz.h"
#include <iostream>
using namespace std;

Autobuz::Autobuz(string id, string marca, int capacitate, int linie, const Ruta& ruta)
    : Vehicul(id, "Autobuz", marca, capacitate),
    linie(linie),
    ruta(ruta) {
}

const Ruta& Autobuz::getRuta() const {
    return ruta;
}

void Autobuz::afiseaza() const {
    cout << "[Autobuz] ";
    Vehicul::afiseaza();

    cout << " Linie: " << linie << "\n";
    cout << " Statii: ";

    for (const auto& s : ruta.getStatii()) {
        cout << s << " ";
    }
    cout << "\n";
}

