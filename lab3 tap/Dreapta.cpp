#include "Dreapta.h"
Dreapta::Dreapta(double m, double n) {
	this->m = 1;
	this->n = 0;
}
Dreapta::Dreapta(Dreapta& other) {
	m = other.m;
	n = other.n;
}
Dreapta::~Dreapta() {

}