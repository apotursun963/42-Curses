
#pragma once

#include <iostream>
#include <math.h>       // cmath.h kullanman gerekiyor ama öyle bir dosya yok diyor

class Fixed {
private:
    int fixed_point_value;          // Sabit noktalı sayının değerini saklar.
    static const int fraction = 8;
public:
    Fixed();
    Fixed(const Fixed &other);       
    Fixed &operator=(const Fixed &other); 
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed(const int num_int);       // Bu constructure, int değerini fixed point formatına çeviriyor.
    Fixed(const float num_flo);     // Bu constructure, float değerini fixed point formatına çeviriyor.
    float toFloat(void) const;      // Sabit noktalı değeri float olarak döndürür.
    int toInt(void) const;          // Sabit noktalı değeri int olarak döndürür.
};
// Sabit noktalı sayının float temsilini ekrana veya bir stream'e yazdırmak için << operatörünü aşırı yüklemen (overload) gerekiyor.
std::ostream &operator<<(std::ostream &out, const Fixed &right);
// Ekrana/akışa float formatında yazdırılabilmeli (<< operatörü ile).
