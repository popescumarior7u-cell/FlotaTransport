#pragma once
#include <vector>
#include <memory>
#include "Vehicul.h"

class Flota 
{
private:
    vector<shared_ptr<Vehicul>> vehicule;

public:
    // Adauga un vehicul în flota?
    void adaugaVehicul(shared_ptr<Vehicul> v);

    // Afiseaza toate vehiculele
    void afiseazaFlota() const;

    // Stergere vehicul
    bool stergeVehicul(const string& id);

    // Cauta vehicul dupa tip
    void cautaDupaTip(const string& tip) const;

    // Filtreaza cautarea in functie de capacitatea vehiculului
    void filtreazaDupaCapacitate(int capacitateMinima) const;

    // Actualizeaza starea vehiculului in functie de disponibilitate
    void actualizeazaStareVehicul(const string& id);

    ///Cautarea rutei directe iar apoi rutei cu un singur schimb
    void gasesteRuta(const string& start, const string& stop) const;

    // Returneaza numarul total de vehicule
    int getNumarVehicule() const;

    // --- Constructori și Destructor ---
    Flota();                              // constructor implicit
    Flota(const Flota& other);            // constructor de copiere
    Flota(Flota&& other) noexcept;        // constructor de mutare
    Flota& operator=(const Flota& other); // operator de copiere
    Flota& operator=(Flota&& other) noexcept; // operator de mutare
    ~Flota();                             // destructor

};
