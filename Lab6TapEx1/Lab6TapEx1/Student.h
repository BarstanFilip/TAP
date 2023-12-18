#pragma once
#include "Persoana.h"
using namespace std;
class Student : public Persoana {
public:
    Student(const string& cnp, const string& nume, const string& email, double nota);
    double getNota() const;
    string detalii() const override;

private:
    string email;
    double nota;
};

