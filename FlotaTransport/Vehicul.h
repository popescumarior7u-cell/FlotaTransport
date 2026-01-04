#pragma once
#include <string>
#include <iostream>
using namespace std;

class Vehicul {
private:
    string id;
    string tip;
    string marca;
    int capacitate;

public:
    // Constructor implicit
    Vehicul();

    // Constructor cu parametri
    Vehicul(string id, string tip, string marca, int capacitate);

    // Constructori si operatori
    Vehicul(const Vehicul& other);            // constructor de copiere
    Vehicul(Vehicul&& other) noexcept;        // constructor de mutare
    Vehicul& operator=(const Vehicul& other); // operator de copiere
    Vehicul& operator=(Vehicul&& other) noexcept; // operator de mutare

    // Destructor
    ~Vehicul();

    // Metoda pentru afisare
    void afiseaza() const;

    // Getters si setters
    string getId() const;
    string getTip() const;
    string getMarca() const;
    int getCapacitate() const;

    void setId(string idNou);
    void setTip(string tipNou);
    void setMarca(string marcaNoua);
    void setCapacitate(int capacitateNoua);
};
