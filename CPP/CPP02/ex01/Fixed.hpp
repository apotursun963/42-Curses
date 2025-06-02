
#pragma once

#include <iostream>

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
    float toFloat(void) const;  // converts the fixed-point value to a floating-point value.
    int toInt(void) const;      // that converts the fixed-point value to an integer value.
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);