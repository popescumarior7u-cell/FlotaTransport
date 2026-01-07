#include "Vehicul.h"
#include <utility>   // pentru std::move
#include <iostream>
using namespace std;

// Constructor implicit
Vehicul::Vehicul()
    : id(""),
    tip(""),
    marca(""),
    capacitate(0),
    stare(StareVehicul::Disponibil) {
}

// Constructor cu parametri
Vehicul::Vehicul(string i, string t, string m, int c)
    : id(i),
    tip(t),
    marca(m),
    capacitate(c),
    stare(StareVehicul::Disponibil) {
}

// Constructor de copiere
Vehicul::Vehicul(const Vehicul& other)
    : id(other.id),
    tip(other.tip),
    marca(other.marca),
    capacitate(other.capacitate),
    stare(other.stare) {
}

// Constructor de mutare
Vehicul::Vehicul(Vehicul&& other) noexcept
    : id(move(other.id)),
    tip(move(other.tip)),
    marca(move(other.marca)),
    capacitate(other.capacitate),
    stare(other.stare) {
    other.capacitate = 0;
}

// Operator de copiere
Vehicul& Vehicul::operator=(const Vehicul& other) {
    if (this != &other) {
        id = other.id;
        tip = other.tip;
        marca = other.marca;
        capacitate = other.capacitate;
        stare = other.stare;
    }
    return *this;
}

// Operator de mutare
Vehicul& Vehicul::operator=(Vehicul&& other) noexcept {
    if (this != &other) {
        id = move(other.id);
        tip = move(other.tip);
        marca = move(other.marca);
        capacitate = other.capacitate;
        stare = other.stare;
        other.capacitate = 0;
    }
    return *this;
}

// Destructor
Vehicul::~Vehicul() {
}

// Afisare vehicul
void Vehicul::afiseaza() const {
    cout << "ID: " << id
        << " | Tip: " << tip
        << " | Marca: " << marca
        << " | Capacitate: " << capacitate << " locuri";

    string stareText = (stare == StareVehicul::Disponibil)
        ? "Disponibil"
        : "Indisponibil";

    cout << " | Stare: " << stareText << "\n";
}

// Getteri
string Vehicul::getId() const { return id; }
string Vehicul::getTip() const { return tip; }
string Vehicul::getMarca() const { return marca; }
int Vehicul::getCapacitate() const { return capacitate; }
StareVehicul Vehicul::getStare() const { return stare; }

// Setteri
void Vehicul::setId(string idNou) { id = idNou; }
void Vehicul::setTip(string tipNou) { tip = tipNou; }
void Vehicul::setMarca(string marcaNoua) { marca = marcaNoua; }
void Vehicul::setCapacitate(int capacitateNoua) { capacitate = capacitateNoua; }
void Vehicul::setStare(StareVehicul stareNoua) { stare = stareNoua; }
