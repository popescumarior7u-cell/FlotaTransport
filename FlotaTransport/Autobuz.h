#pragma once
#include "Vehicul.h"

class Autobuz : public Vehicul {
private:
    int linie;   

public:
    Autobuz(string id, string marca, int capacitate, int linie);
    void afiseaza() const override; 
};
