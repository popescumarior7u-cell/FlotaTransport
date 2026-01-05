#pragma once
#include "Vehicul.h"

class Avion : public Vehicul {
private:
    string aeroportPlecare;
    string aeroportDestinatie;

public:
    Avion(string id, string marca, int capacitate,
        string aeroportPlecare, string aeroportDestinatie);

    void afiseaza() const override;
};
