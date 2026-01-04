#pragma once
#include "Vehicul.h"

class Tren : public Vehicul {
private:
    string ruta;

public:
    Tren(string id, string marca, int capacitate, string ruta);
    void afiseaza() const;
};
