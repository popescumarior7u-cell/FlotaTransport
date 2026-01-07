#include "Tren.h"
#include <iostream>
using namespace std;

Tren::Tren(string id, string marca, int capacitate, const Ruta& ruta)
    : Vehicul(id, "Tren", marca, capacitate),
    ruta(ruta) {
}

const Ruta& Tren::getRuta() const {
    return ruta;
}

void Tren::afiseaza() const {
    cout << "[Tren] ";
    Vehicul::afiseaza();

    cout << " Statii: ";
    for (const auto& s : ruta.getStatii()) {
        cout << s << " ";
    }
    cout << "\n";
}
