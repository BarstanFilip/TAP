#include "Profesor.h"
#include <sstream>
using namespace std;
Profesor::Profesor(const string& cnp, const string& nume, const string& email, const string& materie)
    : Persoana(cnp, nume), email(email), materie(materie) {}

std::string Profesor::getMaterie() const {
    return materie;
}

std::string Profesor::detalii() const {
    ostringstream ss;
    ss << "Profesorul " << nume << " preda " << materie << ".";
    return ss.str();
}

