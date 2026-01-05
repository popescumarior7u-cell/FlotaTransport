#include "Flota.h"
#include <iostream>
#include <memory>
using namespace std;

void Flota::adaugaVehicul(shared_ptr<Vehicul> v) {
    vehicule.push_back(v);
}

void Flota::afiseazaFlota() const {
    cout << "--- Lista vehiculelor din flota ---\n";
    for (const auto& v : vehicule) {
        v->afiseaza(); // POLIMORFISM
    }
}

int Flota::getNumarVehicule() const {
    return (int)vehicule.size();
}


// Constructor implicit
Flota::Flota() {
  
}

// Constructor de copiere
Flota::Flota(const Flota& other)
    : vehicule(other.vehicule) {
 
}

// Constructor de mutare
Flota::Flota(Flota&& other) noexcept
    : vehicule(std::move(other.vehicule)) {
   
}

// Operator de copiere
Flota& Flota::operator=(const Flota& other) {
    if (this != &other) {
        vehicule = other.vehicule;
      
    }
    return *this;
}

// Operator de mutare
Flota& Flota::operator=(Flota&& other) noexcept {
    if (this != &other) {
        vehicule = std::move(other.vehicule);
      
    }
    return *this;
}

// Destructor
Flota::~Flota() {
   
}
