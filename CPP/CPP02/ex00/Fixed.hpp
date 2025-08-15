
#pragma once

#include <iostream>

class Fixed {
private:
    int fixed_point_value;              // Sabit noktalı sayının değerini saklar.
    static const int fraction = 8;      //  Kesirli bit sayısını saklar (her zaman 8 olacak)
public:
    Fixed();                         // Default Constructor: Değeri (fixed-point number) 0’a ayarlar.
    Fixed(const Fixed &other);       // Copy Constructor 
    Fixed &operator=(const Fixed &other); // Copy Assignment Operator (kopya atama operatörü func) (burada = operatürünü overload ediiyoruz)
    ~Fixed();
    int getRawBits(void) const;     // fixed_point_value değerini döndürür.
    void setRawBits(int const raw);  // fixed_point_value'ya raw değerini atar.
};

/*
Assignment Operator (atama operatörü =)
Bir nesneneyi başka bir nesneye kopyalamadır. yani bir nesnenin içindeki verileri başka bir nesneye atamak.
örnek olarak iki tane (a ve b) nesnesi oluşturulur. b nesnesine a atanır (kopyalanır) (ama aynı adresi paylaşmazlar)

overload:
Aynı isimli fonksiyon veya operatörü, farklı parametrelerle birden fazla tanımlayabilmektir. 
ve farklı çalışmasını sağlamak.

- Kopya Kurucu:
Yeni nesne oluşturur ve verileri başka bir nesneden alır.
(Nesne yaratılırken çağrılır.)
- Kopya Atama Operatörü:
Var olan nesnenin verilerini başka bir nesneden alır.
(Nesne zaten var, sadece içeriği değiştiriliyor.)

*/
