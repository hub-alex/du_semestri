#include <iostream>
#include <cstring>
using namespace std;

// Definīcija struktūrai "Valsts"
struct Valsts {
    char galvaspilseta[50]; // Stolica
    char pilseta[50]; // Gorod
    float iedzivotajuSkaits; // Naselenie
    float platiba; // Ploshchad

    // Funkcija, lai aizpildītu valsts datus
    void aizpilditDatus(const char* galvaspilseta, const char* pilseta, float iedzivotajuSkaits, float platiba) {
        strcpy(this->galvaspilseta, galvaspilseta);
        strcpy(this->pilseta, pilseta);
        this->iedzivotajuSkaits = iedzivotajuSkaits;
        this->platiba = platiba;
    }

    // Funkcija, lai izvadītu valsts datus
    void izvaditDatus() {
        cout << "Galvaspilsēta: " << galvaspilseta << endl;
        cout << "Pilsēta: " << pilseta << endl;
        cout << "Iedzīvotāju skaits: " << iedzivotajuSkaits << " miljons" << endl;
        cout << "Platība: " << platiba << " kvadrātkilometri" << endl;
    }
};

int main() {
    Valsts latvija;
    latvija.aizpilditDatus("Rīga", "Liepāja", 1.9, 64589.0);
    latvija.izvaditDatus();

    return 0;
}