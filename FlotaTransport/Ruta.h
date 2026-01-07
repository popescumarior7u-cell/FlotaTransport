#pragma once
#include <vector>
#include <string>
using namespace std;

class Ruta {
private:
    vector<string> statii;

public:
    Ruta() = default;
    Ruta(const vector<string>& statii);

    const vector<string>& getStatii() const;

    bool contineStatia(const string& statie) const;
    bool leaga(const string& start, const string& stop) const;
};

