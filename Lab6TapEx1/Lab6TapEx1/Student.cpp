#include "Student.h"
#include <sstream>
using namespace std;
Student::Student(const string& cnp, const string& nume, const string& email, double nota)
    : Persoana(cnp, nume), email(email), nota(nota) {}

double Student::getNota() const {
    return nota;
}

string Student::detalii() const {
    ostringstream ss;
    ss << "Studentul " << nume << " are nota " << nota << ".";
    return ss.str();
}
