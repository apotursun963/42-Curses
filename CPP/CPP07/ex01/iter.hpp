
#pragma once

#include <iostream>

template <typename T, typename F>   // bu funcs iki tür parametre alır (T, F)
void    iter(T *arr, int len, void(*func)(F)) {
    int i = -1;
    while (++i < len)
        func(arr[i]);
}

template <typename T>
void    cout(T const &value) {
    std::cout << value << std::endl;
}


// test

// class Awesome
// {
// public:
//     Awesome (void): _n(42) { return; }
//     int get(void) const { return this->_n; }
// private:
//     int _n;
// };

// std::ostream & operator<<(std::ostream & o, Awesome const & rhs) {
//     o << rhs.get();
//     return o;
// }

// template<typename T>
// void print( T const & x) {
//     std::cout << x << std::endl;
//     return;
// }

