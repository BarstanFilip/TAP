

#include "complex.h"
#include <cmath>


Complex::Complex() : re(0), im(0) {}

Complex::Complex(double real, double imag) : re(real), im(imag) {}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}


Complex::~Complex() {}

double Complex::getReal() const {
    return re;
}

double Complex::getImaginary() const {
    return im;
}


Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex((re * other.re) - (im * other.im), (re * other.im) + (im * other.re));
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = (other.re * other.re) + (other.im * other.im);
    return Complex(((re * other.re) + (im * other.im)) / denominator, ((im * other.re) - (re * other.im)) / denominator);
}

Complex& Complex::operator+=(const Complex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double tempRe = (re * other.re) - (im * other.im);
    double tempIm = (re * other.im) + (im * other.re);
    re = tempRe;
    im = tempIm;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = (other.re * other.re) + (other.im * other.im);
    double tempRe = ((re * other.re) + (im * other.im)) / denominator;
    double tempIm = ((im * other.re) - (re * other.im)) / denominator;
    re = tempRe;
    im = tempIm;
    return *this;
}


Complex& Complex::operator++() { 
    re++;
    im++;
    return *this;
}

Complex Complex::operator++(int) { 
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    re--;
    im--;
    return *this;
}

Complex Complex::operator--(int) { 
    Complex temp = *this;
    --(*this);
    return temp;
}


std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.re << " + " << c.im << "i";
    return out;
}


std::istream& operator>>(std::istream& in, Complex& c) {
    std::cout << "Introdu partea reala: ";
    in >> c.re;
    std::cout << "Introdu partea imaginara: ";
    in >> c.im;
    return in;
}


double modul(const Complex& c) {
    return sqrt(c.re * c.re + c.im * c.im);
}

Complex conjug;
