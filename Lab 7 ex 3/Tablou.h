#pragma once
#ifndef TABLOU_H
#define TABLOU_H
#include <iostream>
using namespace std;
template <typename T>
class Tablou {
public:

    Tablou(int size);

    
    Tablou(const Tablou& other);


    ~Tablou();

    Tablou& operator=(const Tablou& other);

    T& operator[](int index);

    template <typename U>
    friend ostream& operator<<(ostream& os, const Tablou<U>& arr);

  
    template <typename U>
    friend istream& operator>>(istream& is, Tablou<U>& arr);

private:
    T* elements;
    int size;
};

#endif 
