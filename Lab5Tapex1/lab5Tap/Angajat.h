#pragma once
#ifndef ANGAJAT_H
#define ANGAJAT_H
using namespace std;
#include <iostream>

class Angajat {
private:
    double tarifOrar;
    int nrOre;

public:
    Angajat();
    Angajat(double tarif, int ore);
    Angajat(const Angajat& other);
    ~Angajat();
    Angajat& operator=(const Angajat& other);

    double getTarifOrar() const;
    int getNrOre() const;
    double getSalar() const;

    friend ostream& operator<<(ostream& os, const Angajat& angajat);
    friend istream& operator>>(istream& is, Angajat& angajat);
};

#endif // ANGAJAT_H