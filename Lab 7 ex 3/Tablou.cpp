
#include "Tablou.h"
#include <iostream>

template <typename T>
Tablou<T>::Tablou(int size) : size(size) {
    elements = new T[size];
}

template <typename T>
Tablou<T>::Tablou(const Tablou& other) : size(other.size) {
    elements = new T[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}


template <typename T>
Tablou<T>::~Tablou() {
    delete[] elements;
}

template <typename T>
Tablou<T>& Tablou<T>::operator=(const Tablou& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new T[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}


template <typename T>
T& Tablou<T>::operator[](int index) {
    return elements[index];
}

// Operatorul de afișare <<
template <typename U>
ostream& operator<<(ostream& os, const Tablou<U>& arr) {
    for (int i = 0; i < arr.size; ++i) {
        os << arr.elements[i] << " ";
    }
    return os;
}


template <typename U>
istream& operator>>(istream& is, Tablou<U>& arr) {
    for (int i = 0; i < arr.size; ++i) {
        is >> arr.elements[i];
    }
    return is;
}

template <>
class Tablou<char> {
public:
    Tablou(int size);


private:
    char* characters;
    int size;
};

