[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21176933&assignment_repo_type=AssignmentRepo)

Flota de Transport

## Descriere generala
Acest proiect reprezinta o aplicatie C++ orientata pe obiecte pentru gestionarea unei flote de mijloace de transport, incluzand autobuze, trenuri si avioane.
Aplicatia permite administrarea vehiculelor, cautarea rutelor intre statii si simularea disponibilitatii acestora.

Proiectul este realizat in conformitate cu conceptele studiate la Programare Orientata pe Obiecte.

---

## Functionalitati implementate

### 1. Gestionarea vehiculelor
- Adaugarea de vehicule (Autobuz, Tren, Avion)
- Stergerea unui vehicul dupa ID
- Afisarea intregii flote
- Cautarea vehiculelor dupa tip
- Filtrarea vehiculelor dupa capacitate

### 2. Ierarhii de clase si polimorfism
- Clasa de baza `Vehicul`
- Clase derivate: `Autobuz`, `Tren`, `Avion`
- Utilizarea polimorfismului prin pointeri la clasa de baza (`shared_ptr<Vehicul>`)
- Metode virtuale pentru afisare

### 3. Gestionarea starii vehiculelor
- Fiecare vehicul are o stare: `Disponibil` sau `Indisponibil`
- Posibilitatea de actualizare a starii unui vehicul
- Vehiculele indisponibile nu sunt luate in calcul la cautarea rutelor

### 4. Gestionarea rutelor
- Rutele sunt reprezentate ca liste de statii (`Ruta`)
- Autobuzele si trenurile au rute asociate
- Cautarea unei rute intre doua statii:
  - Ruta directa
  - Ruta cu un singur schimb de vehicul

### 5. Citirea datelor din fisier
- Datele initiale ale flotei sunt citite dintr-un fisier text (`date_intrare.txt`)
- Eliminarea necesitatii introducerii manuale a datelor la rulare
- Fisierul este citit automat la pornirea aplicatiei

### 6. Interfata de tip meniu
- Aplicatia ruleaza in consola
- Meniu interactiv pentru accesarea functionalitatilor
- Posibilitatea de testare usoara a tuturor operatiilor

---

## Structura proiectului
- `Vehicul` – clasa de baza
- `Autobuz`, `Tren`, `Avion` – clase derivate
- `Ruta` – gestiunea listelor de statii
- `Flota` – administrarea colectiei de vehicule
- `main.cpp` – interfata cu utilizatorul si meniul principal
- `date_intrare.txt` – fisier de date pentru initializarea flotei

---

## Tehnologii utilizate
- Limbaj: C++
- Standard: C++11+
- STL: vector, string, smart pointers (`shared_ptr`)
- Programare orientata pe obiecte

---

## Observatii finale
Proiectul respecta cerintele impuse si demonstreaza utilizarea conceptelor fundamentale de OOP: incapsulare, mostenire, polimorfism, gestionarea resurselor si separarea responsabilitatilor.

Aplicatia este extensibila si poate fi dezvoltata ulterior cu functionalitati suplimentare.
