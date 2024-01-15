#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    ifstream inputFile("Input.txt");
    
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    sort(lines.begin(), lines.end());

    ofstream alfabetic("outputAlfabetic.txt");
    for (const auto& l : lines) {
        alfabetic << l << endl;
    }
    alfabetic.close();

  
    sort(lines.rbegin(), lines.rend());

    ofstream inversAlfabetic("outputInversAlfabetic.txt");
    for (const auto& l : lines) {
        inversAlfabetic << l << endl;
    }
    inversAlfabetic.close();

  
    sort(lines.begin(), lines.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
        });

    
    ofstream dupaLungime("outputDupaLungime.txt");
    for (const auto& l : lines) {
        dupaLungime << l << endl;
    }
    dupaLungime.close();

   

    return 0;
}
