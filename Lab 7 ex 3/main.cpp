#include "Tablou.h"
#include <iostream>
using namespace std;
int main() {

    Tablou<int> intArray(5);
   cout << "Introduceti 5 numere intregi ";
    cin >> intArray;
   cout << "Tabloul generat este " << intArray << endl;

    
    Tablou<char> charArray(10);
    cout << "Introduceti 10 caractere  ";
   cin >> charArray;
cout << "Tabloulgenerat este " << charArray << endl;

    return 0;
}
