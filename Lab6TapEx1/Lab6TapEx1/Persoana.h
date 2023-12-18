#pragma once
#include <string>
using namespace std;
class Persoana {
public:
    Persoana(const string& cnp, const string& nume);
    virtual ~Persoana();

    virtual string detalii() const = 0;

protected:
    string CNP;
    string nume;
};
