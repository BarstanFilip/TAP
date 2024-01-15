#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename Iterator, typename T>
void inlocuire(Iterator first, Iterator last, const T& valoareDeInlocuit, const T& nouaValoare) {
    replace(first, last, valoareDeInlocuit, nouaValoare);
}

int main() {
  
    vector <int> vector = { 1, 2, 3, 4, 1, 5, 1 };

    cout << "V initial ";
    for (const auto& element : vector) {
        cout << element << " ";
    }
    cout << endl;

    inlocuire(vector.begin(), vector.end(), 1, 10);

   cout << "V dupa inlocuire ";
    for (const auto& element : vector) {
        cout << element << " ";}
   cout << endl;

    return 0;
}