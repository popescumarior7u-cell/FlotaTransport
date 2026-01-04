#pragma once
#include <vector>
#include "Vehicul.h"

class Flota 
{
private:
    vector<Vehicul> vehicule;

public:
    // Adauga un vehicul în flota?
    void adaugaVehicul(const Vehicul& v);

    // Afiseaza? toate vehiculele
    void afiseazaFlota() const;

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
