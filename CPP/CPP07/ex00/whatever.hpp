
#pragma once

#include <iostream>

template <typename T>
void    swap(T &num1, T &num2) {
    T tmp = num1;
    num1 = num2;
    num2 = tmp;
}

template <typename T>
T    min(T num1, T num2) {
    if (num2 <= num1)
        return (num2);
    else
        return (num1);
}

template <typename T>
T    max(T num1, T num2) {
    if (num2 >= num1)
        return (num2);
    else
        return (num1);
}



// test

// class Awesome
// {
// public:
//     Awesome(void): _n(0) {}
//     Awesome(int n):_n(n) {}
//     Awesome & operator=(Awesome & a) { _n = a._n; return *this; }
//     bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
//     bool operator!=(Awesome const & rhs) const{ return (this->_n != rhs._n); }
//     bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
//     bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
//     bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
//     bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }
// private:
//     int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a) { 
//     o << a.get_n();
//     return o;
// }

// int main(void)
// {
//     Awesome a(2), b(4);
//     swap(a, b);

//     std::cout << a << " " << b << std::endl;
//     std::cout << max(a, b) << std::endl;
//     std::cout << min(a, b) << std::endl;
    
//     return (0);
// }
