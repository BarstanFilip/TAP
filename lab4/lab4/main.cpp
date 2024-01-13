#include "Fractie.h"
#include <iostream>
int main() {
    int m;
    int n;
    std::cout << "Introduceti m";
    std::cin >> m;
    std::cout << "Introduceti n";
    std::cin >> n;
        Fractie fractia(m, n);
    Fractie fractie2(1, 4);
    fractia.display();

    Fractie rezultatAdunare = fractia + fractie2;
    rezultatAdunare.display();


    ++fractia;
    fractia.display();

    return 0;
}