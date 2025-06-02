
#pragma once

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed();                         // Default Constructor
    Fixed(const Fixed &other);       // Copy Constructor 
    Fixed &operator=(const Fixed &other); // Copy Assignment Operator (atama operatörü func)
    ~Fixed();
    int getRawBits(void) const;     // value değerini döndürür. const olduğu için nesneyi değiştirmez.
    void setRawBits(int const raw);  // value'ya raw değerini atar.
};

/*
Assignment Operator (atama operatörü =)
Bir nesneneyi başka bir nesneye kopyalamadır. yani bir nesnenin içindeki verileri başka bir nesneye atamak.
örnek olarak iki tane (a ve b) nesnesi oluşturulur. b nesnesine a atanır (kopyalanır) (ama aynı adresi paylaşmazlar)
*/
