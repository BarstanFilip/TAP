#include "Punct.h"
#include <stdio.h>
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cout << "Introduceti numarl de puncte";
	std::cin >> n;

	std::vector<Punct>vectorpuncte;
	for (int i = 0; i < n; ++i) {
		double x, y;
		std::cout << "Introduceti coordonata pentru x= ";
		std::cin >> x;
		std::cout << "Introduceti coordonata pentru y= ";
		std::cin >> y;
		Punct punctNou(x, y);
		vectorpuncte.push_back(punctNou);
	}

	Punct punct1(0, 0);
	Punct punct2(3, 4);
	double distantadintrepuncte = distanta(punct1,punct2);
	std::cout << "Distanta dintre punct1 si punct2 este: =" << distantadintrepuncte << std::endl;

	return 0;
}