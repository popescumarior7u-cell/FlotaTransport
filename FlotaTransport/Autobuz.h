#pragma once
#include "Vehicul.h"
#include "Ruta.h"


class Autobuz : public Vehicul {
private:
    int linie;   
    Ruta ruta;

public:
    Autobuz(string id, string marca, int capacitate, int linie, const Ruta& ruta);
    const Ruta& getRuta() const;
    void afiseaza() const override; 
};
