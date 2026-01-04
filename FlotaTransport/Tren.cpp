#include "Tren.h"
#include <iostream>
using namespace std;

Tren::Tren(string id, string marca, int capacitate, string ruta)
    : Vehicul(id, "Tren", marca, capacitate), ruta(ruta) {
}

void Tren::afiseaza() const {
    cout << "[Tren] ";
    Vehicul::afiseaza();
    cout << " Ruta: " << ruta << "\n";
}