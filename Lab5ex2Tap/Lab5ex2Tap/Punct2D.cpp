#include "Punct2D.h"
#include <cmath>

Punct2D::Punct2D() : x(0.0), y(0.0) {}

Punct2D::Punct2D(double x, double y) : x(x), y(y) {}

Punct2D::~Punct2D() {}

Punct2D& Punct2D::operator=(const Punct2D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Punct2D::operator<(const Punct2D& other) const {
    return (x < other.x) || ((x == other.x) && (y < other.y));
}

bool Punct2D::operator<=(const Punct2D& other) const {
    return (x < other.x) || ((x == other.x) && (y <= other.y));
}

bool Punct2D::operator>(const Punct2D& other) const {
    return (x > other.x) || ((x == other.x) && (y > other.y));
}

bool Punct2D::operator>=(const Punct2D& other) const {
    return (x > other.x) || ((x == other.x) && (y >= other.y));
}

bool Punct2D::operator==(const Punct2D& other) const {
    return (x == other.x) && (y == other.y);
}

bool Punct2D::operator!=(const Punct2D& other) const {
    return (x != other.x) || (y != other.y);
}

Punct2D Punct2D::operator+(const Punct2D& other) const {
    return Punct2D(x + other.x, y + other.y);
}

Punct2D Punct2D::operator-(const Punct2D& other) const {
    return Punct2D(x - other.x, y - other.y);
}

Punct2D Punct2D::operator*(double scalar) const {
    return Punct2D(x * scalar, y * scalar);
}

Punct2D& Punct2D::operator+=(const Punct2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Punct2D& Punct2D::operator-=(const Punct2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Punct2D& Punct2D::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Punct2D& Punct2D::operator/=(double scalar) {
    if (scalar != 0) {
        x /= scalar;
        y /= scalar;
    }
    return *this;
}

Punct2D Punct2D::operator++() {
    ++x;
    ++y;
    return *this;
}

Punct2D Punct2D::operator--() {
    --x;
    --y;
    return *this;
}

Punct2D Punct2D::operator++(int) {
    Punct2D temp(*this);
    ++(*this);
    return temp;
}

Punct2D Punct2D::operator--(int) {
    Punct2D temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(ostream& os, const Punct2D& punct) {
    os << "(" << punct.x << ", " << punct.y << ")";
    return os;
}

std::istream& operator>>(istream& is, Punct2D& punct) {
    is >> punct.x >> punct.y;
    return is;
}

double Punct2D::distanta(const Punct2D& other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}
