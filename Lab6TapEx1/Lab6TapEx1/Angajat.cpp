#include "Angajat.h"
#include <sstream>
using namespace std;
Angajat::Angajat(const std::string& cnp, const std::string& nume, const std::string& email, const std::string& departament)
    : Persoana(cnp, nume), email(email), departament(departament) {}

std::string Angajat::getDepartament() const {
    return departament;
}

std::string Angajat::detalii() const {
    ostringstream ss;
    ss << "Angajatul " << nume << " face parte din departamentul " << departament << ".";
    return ss.str();
}

