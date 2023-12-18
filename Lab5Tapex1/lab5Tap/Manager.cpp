#include "Manager.h"
using namespace std;

Manager::Manager() : Angajat(), numarSubordonati(0) {}

Manager::Manager(double tarif, int ore, int subordonati) : Angajat(tarif, ore), numarSubordonati(subordonati) {}

Manager::Manager(const Manager& other) : Angajat(other), numarSubordonati(other.numarSubordonati) {}

Manager::~Manager() {}

Manager& Manager::operator=(const Manager& other) {
    if (this != &other) {
        Angajat::operator=(other);
        numarSubordonati = other.numarSubordonati;
    }
    return *this;
}

double Manager::getSalar() const {
    // Adaugăm un bonus de 50% la salariul de bază al managerului
    return Angajat::getSalar() * 1.5;
}

ostream& operator<<(ostream& os, const Manager& manager) {
    os << static_cast<const Angajat&>(manager) << ", Numar Subordonati: " << manager.numarSubordonati;
    return os;
}

std::istream& operator>>(istream& is, Manager& manager) {
    Angajat& base = manager; 
    is >> base;
 cout << "Introduceti numarul de subordonati: ";
    is >> manager.numarSubordonati;
    return is;
}
