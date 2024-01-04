#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
  
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
     cerr << "Nu s-a putut deschide fisierul\n";
        return 1;
    }

    
    map<string, unsigned> numaraCuvant;

  
    string cuvant;
    while (inputFile >> cuvant) {
      
        cuvant.erase(remove_if(cuvant.begin(), cuvant.end(), [](char c) {
            return !isalpha(c);
            }), cuvant.end());

      
        if (cuvant.empty()) {
            continue;
        }

        
        transform(cuvant.begin(), cuvant.end(), cuvant.begin(), ::tolower);

        
        numaraCuvant[cuvant]++;
    }

  
    inputFile.close();

    for (const auto& perechi : numaraCuvant) {
        cout << "Cuvantul " << perechi.first << ", nr aparitii " << perechi.second << "\n";
    }

    return 0;
}