#include "Angajat.h"
using namespace std;
Angajat::Angajat() : tarifOrar(5.5), nrOre(0) {}

Angajat::Angajat(double tarif, int ore) : tarifOrar(tarif), nrOre(ore) {}

Angajat::Angajat(const Angajat& other) : tarifOrar(other.tarifOrar), nrOre(other.nrOre) {}

Angajat::~Angajat() {}

Angajat& Angajat::operator=(const Angajat& other) {
    if (this != &other) {
        tarifOrar = other.tarifOrar;
        nrOre = other.nrOre;
    }
    return *this;
}

double Angajat::getTarifOrar() const {
    return tarifOrar;
}

int Angajat::getNrOre() const {
    return nrOre;
}

double Angajat::getSalar() const {
    return tarifOrar * nrOre;
}

std::ostream& operator<<(std::ostream& os, const Angajat& angajat) {
    os << "Tarif Orar: " << angajat.tarifOrar << ", Nr. Ore: " << angajat.nrOre;
    return os;
}

std::istream& operator>>(std::istream& is, Angajat& angajat) {
    cout << "Introduceti tariful orar: ";
    is >> angajat.tarifOrar;
    cout << "Introduceti numarul de ore lucrate: ";
    is >> angajat.nrOre;
    return is;
}