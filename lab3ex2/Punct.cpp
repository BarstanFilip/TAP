#include "Punct.h"
#include <math.h>


Punct::Punct(double x, double y) {
	this->x = x;
	this->y = y;
}

Punct::Punct(const Punct& other) {
	this->x = other.x;
	this->y = other.y;
}
double distanta(const Punct& punct1,const Punct& punct2){
	double dist = sqrt(pow(punct2.x - punct1.x,2) + pow(punct2.y - punct1.y,2));
	return dist;

}
Punct::~Punct() {

	}