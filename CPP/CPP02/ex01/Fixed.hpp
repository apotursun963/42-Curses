
#pragma once

#include <iostream>
#include <math.h>

class Fixed {
private:
    int fixed_point_value;          // Sabit noktalı sayının değerini saklar.
    static const int fraction = 8;
public:
    Fixed();                         
    Fixed(const Fixed &other);       
    Fixed &operator=(const Fixed &other); 
    ~Fixed();
    Fixed(const int num_int);
    Fixed(const float num_flo);
    float toFloat(void) const;  // Sabit noktalı değeri float olarak döndürür.
    int toInt(void) const;      // Sabit noktalı değeri int olarak döndürür.
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
// Sabit noktalı sayının float temsilini ekrana veya bir stream'e yazdırmak için << operatörünü aşırı yüklemen (overload) gerekiyor.
std::ostream &operator<<(std::ostream &out, const Fixed &right);
// Ekrana/akışa float formatında yazdırılabilmeli (<< operatörü ile).
