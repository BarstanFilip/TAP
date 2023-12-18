#include "Angajat.h"
#include "Manager.h"
using namespace std;

int main() {
    // Testare clasa Angajat
    Angajat angajat;
    cin >> angajat;
    cout << "Angajatul: " << angajat << ", Salar: " << angajat.getSalar() << std::endl;

    // Testare clasa Manager
    Manager manager;
 cin >> manager;
cout << "Managerul: " << manager << ", Salar: " << manager.getSalar() << std::endl;

    return 0;
}
