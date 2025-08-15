
#pragma once

#include <iostream>

// value = 5
// fixed point değeri = 1280
// 0.01953125
class Fixed {
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed(const int num_int);
    Fixed(const float num_flo);
    Fixed();                         
    Fixed(const Fixed &other);       
    Fixed &operator=(const Fixed &other); 
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    // Karşılaştırma Operatörleri
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Aritmetik Operatörleri
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Artırma/Azaltma Operatörleri
    Fixed &operator++();    // pre-increment (++a)
    Fixed operator++(int);  // post-increment (a++)
    Fixed &operator--();    // pre-decrement (--a)
    Fixed operator--(int);  // post-decrement (a--)

    // Static min ve max Fonksiyonları
    static Fixed &min(Fixed &Fixed1, Fixed &Fixed2);
    static const Fixed &min(const Fixed &Fixed1, const Fixed &Fixed2);
    static Fixed &max(Fixed &Fixed1, Fixed &Fixed2);
    static const Fixed &max(const Fixed &Fixed1, const Fixed &Fixed2);

};

std::ostream &operator<<(std::ostream &out, const Fixed &right);