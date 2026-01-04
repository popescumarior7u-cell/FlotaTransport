#pragma once
#include "Vehicul.h"

class Autobuz : public Vehicul {
private:
    string linie;

public:
    Autobuz(string id, string marca, int capacitate, string linie);
    void afiseaza() const; // metoda normala, fara virtual/override
};
