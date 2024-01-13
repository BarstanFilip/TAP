
#include "Fractie.h"
#include <iostream>

Fractie::Fractie() {
	numarator = 0;
	numitor = 0;
}
Fractie::Fractie(int numarator) {
	this->numarator = numarator;
	numitor = 1;
}

Fractie::Fractie(int numarator, int numitor) {
	this->numarator = numarator;
	if (numitor != 0) {
		this->numitor = numitor;
	}
	else {
		std::cout << "Numitorul nu poate fi 0" << std::endl;
		this->numitor = 1;
	}
}

Fractie::Fractie(const Fractie& other) {
	this->numarator = other.numarator;
	this->numitor = other.numitor;
}
void Fractie::display() {
	std::cout << numarator << "/" << numitor << std::endl;
}

Fractie Fractie::operator+(const Fractie& f) {
	Fractie rezultat;
	rezultat.numarator = this->numarator * f.numitor + f.numarator * this->numitor;
	rezultat.numitor = this->numitor * f.numitor;
	return rezultat;
}
Fractie Fractie::operator-(const Fractie& f) {
	Fractie rezultat;
	rezultat.numarator = this->numarator * f.numitor - f.numarator * this->numitor;
	rezultat.numitor = this->numitor * f.numitor;
	return rezultat;
}

Fractie Fractie::operator*(const Fractie& f) {
	Fractie rezultat;
	rezultat.numarator = this->numarator * f.numarator;
	rezultat.numitor = this->numitor * f.numitor;
	return rezultat;
}

Fractie Fractie::operator/(const Fractie& f) {
	Fractie rezultat;
	rezultat.numarator = this->numarator * f.numitor;
	rezultat.numitor = this->numitor * f.numarator;
	return rezultat;
}


//suprascriere operatorului de afisare

std::ostream& operator<<(std::ostream& os, const Fractie& f) {
	os << f.numitor << "/" << f.numarator;
	return os;
}

Fractie& Fractie::operator++() {
	this->numarator += this->numitor;
	return *this;
}

Fractie& Fractie::operator--() {
	this->numarator -= this->numitor;
	return *this;
}


Fractie Fractie::operator++(int) {
	Fractie temp(*this);
	++(*this);
	return temp;
}

Fractie Fractie::operator--(int) {
	Fractie temp(*this);
	--(*this);
	return temp;
}