

#include "Serialization.hpp"


Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &other) {(void)other;}
Serializer &Serializer::operator=(const Serializer &other) {(void)other; return (*this);}


/* 
uintptr_t -> Unsigned integer tipidir (yani işaretsiz tamsayı).
Herhangi bir pointer’ı (adres) kayıpsız şekilde saklayabilecek kapasitede garanti edilir.
*/

// Görev: Pointer’ı (adres) sayıya dönüştürmek
uintptr_t   Serializer::serialize(Data *ptr) {      // pointer -> integer
    return (reinterpret_cast<uintptr_t>(ptr));
}

// Görev: Sayıyı tekrar pointer’a dönüştürmek.
Data*       Serializer::deserialize(uintptr_t raw) {    // integer -> pointer
    return (reinterpret_cast<Data*>(raw));
}
