
#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixed_point_value;     
    static const int fractional_bit = 8;
public:
    Fixed();
    Fixed(const Fixed &other);       
    Fixed &operator=(const Fixed &other); 
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed(const int num_int);  
    Fixed(const float num_flo);
    float toFloat(void) const; 
    int toInt(void) const;     
};
std::ostream &operator<<(std::ostream &out, const Fixed &right);
