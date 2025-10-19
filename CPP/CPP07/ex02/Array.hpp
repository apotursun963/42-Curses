
#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>
class Array {
private:
    T   *arr;
    unsigned int _size;

public:
    Array() : arr(new T[0]), _size(0) {}
    Array(unsigned int n) : arr(new T[n]), _size(n) {}      // n elemanlı bir dizi oluşturur.
    Array(const Array &other) : arr(new T[other._size]), _size(other._size) {
        for (unsigned int i=0; i < _size; i++)
            arr[i] = other.arr[i];
    }   // copy constructure ve asssigmentte deep copy olması gerekiyor
    Array &operator=(Array const &other) {
        if (this != &other) {
            delete[] arr;
            _size = other._size;
            arr = new T[_size];
            for (unsigned int i=0; i < _size; i++)
                this->arr[i] = other.arr[i];                
        }
        return (*this);
    }
    ~Array() { delete[] this->arr; }

    // Eğer index sınır dışındaysa (index >= _size) std::exception fırlatmalı.
    // operator[] ile dizi elemanlarına erişebilmemiz gerekiyor
    // iki tane operator[] yeterlimi yoksa 1 tane yeterlimi kontrol et
    T   operator[](unsigned int idx) const {
        if (idx >= _size)
            throw (Array::OutOfRangeException());
        return (this->arr[idx]);
    }
    T   &operator[](unsigned int idx) {
        if (idx >= _size)
            throw (Array::OutOfRangeException());
        return (this->arr[idx]);
    }

    int size() const { return (this->_size); }

    class OutOfRangeException: public std::exception {
        const char *what() const throw() {
            return ("index is out of the range array");
        }
    };
};
