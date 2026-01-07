#pragma once
#include "Vehicul.h"
#include "Ruta.h"

class Tren : public Vehicul {
private:
 
    Ruta ruta;

public:
    Tren(string id, string marca, int capacitate, const Ruta& ruta);
    const Ruta& getRuta() const;
    void afiseaza() const override;
};
