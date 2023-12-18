#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "Angajat.h"

class Manager : public Angajat {
private:
    int numarSubordonati;

public:
    Manager();
    Manager(double tarif, int ore, int subordonati);
    Manager(const Manager& other);
    ~Manager();
    Manager& operator=(const Manager& other);
   
    double getSalar();

    friend ostream& operator<<(ostream& os, const Manager& manager);
    friend istream& operator>>(istream& is, Manager& manager);
};

#endif // MANAGER_H