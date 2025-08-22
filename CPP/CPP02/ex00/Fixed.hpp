
#pragma once

#include <iostream>

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
};
