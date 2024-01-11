#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main() {

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Nu s-a putut deschide fisierul input.txt.\n";
        return 1;
    }

   
    set<string> cvUnice;

  string cuvant;
    while (inputFile >> cuvant) {
        
        cuvant.erase(remove_if(cuvant.begin(), cuvant.end(), [](char c) {
            return !isalpha(c);
            }), cuvant.end());

   
        if (cuvant.empty()) {
            continue;
        }

       
        transform(cuvant.begin(), cuvant.end(), cuvant.begin(), ::tolower);

        cvUnice.insert(cuvant);
    }


    inputFile.close();

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
       cerr << "nu se poate deschide fisierul.\n";
        return 1;
    }

  
    for (const auto& cUnic : cvUnice) {
        outputFile << cUnic << "\n";
    }

   
    outputFile.close();

   cout << "Verificati output.\n";

    return 0;
}