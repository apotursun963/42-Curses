

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

// leak kontrolü yap
template <typename T>
class Array {
public:
    Array() : arr(new T[0]), _size(0) {}
    Array(unsigned int n) : arr(new T[n]), _size(n) {}
    Array(const Array &other) { *this = other; }
    Array &operator=(Array const &other) {
        if (this == &other)
            return (*this);
        else {
            delete[] this->arr;
            this->arr = new T[other._size];
            this->_size = other._size;
            int i = -1;
            while (++i < other._size)
                this->arr[i] = other.arr[i];
        }
        return (*this);
    }
    ~Array() { delete[] this->arr; }

    // Eğer index sınır dışındaysa (index >= _size) std::exception fırlatmalı.
    T   operator[](int idx) const {
        if (idx <= this->_size - 1)
            return (this->arr[idx]);
        throw (Array::OutOfRangeException());
    }
    T   &operator[](int idx) {
        if (idx <= this->_size - 1)
            return (this->arr[idx]);
        throw (Array::OutOfRangeException());
    }
    int size() const {
        return (this->_size);
    }

    class OutOfRangeException: public std::exception {
        const char *what() const throw() {
            return ("Value is out of the range array");
        }
    };
private:
    T   *arr;
    int _size;
};
