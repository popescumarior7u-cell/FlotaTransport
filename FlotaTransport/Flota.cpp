#include "Flota.h"
#include <iostream>
using namespace std;

void Flota::adaugaVehicul(const Vehicul& v) {
    vehicule.push_back(v);
}

void Flota::afiseazaFlota() const {
    cout << "\n--- Lista vehiculelor din flota ---\n";
    for (const auto& v : vehicule) {
        v.afiseaza();
    }
}

int Flota::getNumarVehicule() const {
    return (int)vehicule.size();
}
#include "Flota.h"

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
