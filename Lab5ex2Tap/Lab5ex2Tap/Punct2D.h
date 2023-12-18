#pragma once
#ifdef PUNCT2D_H
#define PUNCT2D_H

#include <iostream>

class Punct2D {
public:
    Punct2D();
    Punct2D(double x, double y);
    ~Punct2D();

    Punct2D& operator=(const Punct2D& other);

    bool operator<(const Punct2D& other) const;
    bool operator<=(const Punct2D& other) const;
    bool operator>(const Punct2D& other) const;
    bool operator>=(const Punct2D& other) const;
    bool operator==(const Punct2D& other) const;
    bool operator!=(const Punct2D& other) const;

    Punct2D operator+(const Punct2D& other) const;
    Punct2D operator-(const Punct2D& other) const;
    Punct2D operator*(double scalar) const;

    Punct2D& operator+=(const Punct2D& other);
    Punct2D& operator-=(const Punct2D& other);
    Punct2D& operator*=(double scalar);
    Punct2D& operator/=(double scalar);

    Punct2D operator++();    // pre-increment
    Punct2D operator--();    // pre-decrement
    Punct2D operator
#endif // PUNCT2D_H