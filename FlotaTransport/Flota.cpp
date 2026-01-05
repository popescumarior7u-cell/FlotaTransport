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

bool Flota::stergeVehicul(const string& id) {
    for (auto it = vehicule.begin(); it != vehicule.end(); ++it) {
        if ((*it)->getId() == id) {
            vehicule.erase(it);
            return true;
        }
    }
    return false;
}

void Flota::cautaDupaTip(const string& tip) const {
    bool gasit = false;
    for (const auto& v : vehicule) {
        if (v->getTip() == tip) {
            v->afiseaza();
            gasit = true;
        }
    }
    if (!gasit) {
        cout << "Nu exista vehicule de tipul cautat.\n";
    }
}

void Flota::filtreazaDupaCapacitate(int capacitateMinima) const {
    bool gasit = false;
    for (const auto& v : vehicule) {
        if (v->getCapacitate() >= capacitateMinima) {
            v->afiseaza();
            gasit = true;
        }
    }
    if (!gasit) {
        cout << "Nu exista vehicule cu capacitatea ceruta.\n";
    }
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
