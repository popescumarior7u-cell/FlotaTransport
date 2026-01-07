#include "Ruta.h"

Ruta::Ruta(const vector<string>& statii) : statii(statii) {}

const vector<string>& Ruta::getStatii() const {
    return statii;
}

bool Ruta::contineStatia(const string& statie) const {
    for (const auto& s : statii)
        if (s == statie)
            return true;
    return false;
}

bool Ruta::leaga(const string& start, const string& stop) const {
    bool gasitStart = false;
    for (const auto& s : statii) {
        if (s == start)
            gasitStart = true;
        if (gasitStart && s == stop)
            return true;
    }
    return false;
}
