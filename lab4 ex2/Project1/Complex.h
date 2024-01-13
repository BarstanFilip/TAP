#// complex.h

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double re, im;

public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& other);
    ~Complex();

    double getReal() const;
    double getImaginary() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex& operator++(); 
    Complex operator++(int); 
    Complex& operator--(); 
    Complex operator--(int); 

    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
    friend double modul(const Complex& c);
    friend Complex conjugat(const Complex& c);
};

#endif // COMPLEX_H
