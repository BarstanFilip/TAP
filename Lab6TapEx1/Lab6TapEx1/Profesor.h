#pragma once
#include "Persoana.h"
using namespace std;
class Profesor : public Persoana {
public:
    Profesor(const string& cnp, const string& nume, const string& email, const string& materie);
    string getMaterie() const;
    string detalii() const override;

private:
    string email;
    string materie;
};

