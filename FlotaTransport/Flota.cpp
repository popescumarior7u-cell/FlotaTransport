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

void Flota::actualizeazaStareVehicul(const string& id) {
    for (auto& v : vehicule) {
        if (v->getId() == id) {
            cout << "Alege noua stare:\n";
            cout << "0 - Disponibil\n";
            cout << "1 - Indisponibil\n";

            int opt;
            cin >> opt;

            if (opt == 0) {
                v->setStare(StareVehicul::Disponibil);
            }
            else if (opt == 1) {
                v->setStare(StareVehicul::Indisponibil);
            }
            else {
                cout << "Optiune invalida.\n";
                return;
            }

            cout << "Stare actualizata cu succes.\n";
            return;
        }
    }

    cout << "Vehiculul nu a fost gasit.\n";
}

#include "Autobuz.h"
#include "Tren.h"

void Flota::gasesteRuta(const string& start, const string& stop) const {
    cout << "\n--- Cautare ruta de la " << start << " la " << stop << " ---\n";

    // =========================
    // 1. Ruta directa
    // =========================
    for (const auto& v : vehicule) {
        if (v->getStare() != StareVehicul::Disponibil)
            continue;

        if (auto a = dynamic_pointer_cast<Autobuz>(v)) {
            if (a->getRuta().leagaBidirectional(start, stop)) {
                cout << "Ruta directa gasita:\n";
                cout << "Vehicul " << a->getId() << " (Autobuz): "
                    << start << " -> " << stop << "\n";

                cout << "   Detalii vehicul:\n";
                a->Vehicul::afiseaza();
                cout << "\n";
                return;
            }
        }

        if (auto t = dynamic_pointer_cast<Tren>(v)) {
            if (t->getRuta().leagaBidirectional(start, stop)) {
                cout << "Ruta directa gasita:\n";
                cout << "Vehicul " << t->getId() << " (Tren): "
                    << start << " -> " << stop << "\n";

                cout << "   Detalii vehicul:\n";
                t->Vehicul::afiseaza();
                cout << "\n";
                return;
            }
        }
    }

    // =========================
    // 2. Ruta cu un singur schimb
    // =========================
    for (const auto& v1 : vehicule) {
        if (v1->getStare() != StareVehicul::Disponibil)
            continue;

        for (const auto& v2 : vehicule) {
            if (v2->getStare() != StareVehicul::Disponibil)
                continue;

            if (v1 == v2)
                continue;

            // -------- v1 Autobuz --------
            if (auto a1 = dynamic_pointer_cast<Autobuz>(v1)) {
                for (const auto& statie : a1->getRuta().getStatii()) {

                    // Autobuz -> Autobuz
                    if (auto a2 = dynamic_pointer_cast<Autobuz>(v2)) {
                        if (a1->getRuta().leaga(start, statie) &&
                            a2->getRuta().leaga(statie, stop)) {

                            cout << "Ruta gasita cu un singur schimb:\n";
                            cout << "1) Autobuz " << a1->getId() << ": "
                                << start << " -> " << statie << "\n";

                            cout << "   Detalii vehicul:\n";
                            a1->Vehicul::afiseaza();
                            cout << "\n";

                            cout << "2) Autobuz " << a2->getId() << ": "
                                << statie << " -> " << stop << "\n";

                            cout << "   Detalii vehicul:\n";
                            a2->Vehicul::afiseaza();
                            cout << "\n";

                            return;
                        }
                    }

                    // Autobuz -> Tren
                    if (auto t2 = dynamic_pointer_cast<Tren>(v2)) {
                        if (a1->getRuta().leaga(start, statie) &&
                            t2->getRuta().leagaBidirectional(statie, stop)) {

                            cout << "Ruta gasita cu un singur schimb:\n";
                            cout << "1) Autobuz " << a1->getId() << ": "
                                << start << " -> " << statie << "\n";

                            cout << "   Detalii vehicul:\n";
                            a1->Vehicul::afiseaza();
                            cout << "\n";

                            cout << "2) Tren " << t2->getId() << ": "
                                << statie << " -> " << stop << "\n";

                            cout << "   Detalii vehicul:\n";
                            t2->Vehicul::afiseaza();
                            cout << "\n";

                            return;
                        }
                    }
                }
            }

            // -------- v1 Tren --------
            if (auto t1 = dynamic_pointer_cast<Tren>(v1)) {
                for (const auto& statie : t1->getRuta().getStatii()) {

                    // Tren -> Autobuz
                    if (auto a2 = dynamic_pointer_cast<Autobuz>(v2)) {
                        if (t1->getRuta().leagaBidirectional(start, statie) &&
                            a2->getRuta().leaga(statie, stop)) {

                            cout << "Ruta gasita cu un singur schimb:\n";
                            cout << "1) Tren " << t1->getId() << ": "
                                << start << " -> " << statie << "\n";

                            cout << "   Detalii vehicul:\n";
                            t1->Vehicul::afiseaza();
                            cout << "\n";

                            cout << "2) Autobuz " << a2->getId() << ": "
                                << statie << " -> " << stop << "\n";

                            cout << "   Detalii vehicul:\n";
                            a2->Vehicul::afiseaza();
                            cout << "\n";

                            return;
                        }
                    }

                    // Tren -> Tren
                    if (auto t2 = dynamic_pointer_cast<Tren>(v2)) {
                        if (t1->getRuta().leagaBidirectional(start, statie) &&
                            t2->getRuta().leagaBidirectional(statie, stop)) {

                            cout << "Ruta gasita cu un singur schimb:\n";
                            cout << "1) Tren " << t1->getId() << ": "
                                << start << " -> " << statie << "\n";

                            cout << "   Detalii vehicul:\n";
                            t1->Vehicul::afiseaza();
                            cout << "\n";

                            cout << "2) Tren " << t2->getId() << ": "
                                << statie << " -> " << stop << "\n";

                            cout << "   Detalii vehicul:\n";
                            t2->Vehicul::afiseaza();
                            cout << "\n";

                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "Nu exista ruta disponibila intre cele doua statii.\n";
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
