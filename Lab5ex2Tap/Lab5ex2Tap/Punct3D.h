#pragma once
#ifndef PUNCT3D_H
#define PUNCT3D_H

#include "Punct2D.h"

class Punct3D : public Punct2D {
public:
    Punct3D();
    Punct3D(double x, double y, double z);
    ~Punct3D();

    Punct3D& operator=(const Punct3D& other);

    bool operator<(const Punct3D& other) const;
    bool operator<=(const Punct3D& other) const;
    bool operator>(const Punct3D& other) const;
    bool operator>=(const Punct3D& other) const;
    bool operator==(const Punct3D& other) const;
    bool operator!=(const Punct3D& other)
#endif // PUNCT3D_H