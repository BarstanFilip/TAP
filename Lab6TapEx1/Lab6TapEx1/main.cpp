#include "Student.h"
#include "Profesor.h"
#include "Angajat.h"
#include <iostream>
using namespace std;
int main() {
    
    Student student("1234567890123", "dada sa", "saa.sa@example.com", 9.5);
    cout << student.detalii() << "\n\n";

  
    Profesor profesor("9876543210987", "jsahj sadfa", "sad.dsad@example.com", "Matematica");
    cout << profesor.detalii() << "\n\n";

    Angajat angajat("5678901234567", "shaj sausa", "dsa.asda@example.com", "IT");
    cout << angajat.detalii() << "\n";

    return 0;
}