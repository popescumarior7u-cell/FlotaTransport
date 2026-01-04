#pragma once
#include "Vehicul.h"

class Avion : public Vehicul {
private:
    string aeroportDestinatie;

public:
    Avion(string id, string marca, int capacitate, string aeroportDestinatie);
    void afiseaza() const;
};
