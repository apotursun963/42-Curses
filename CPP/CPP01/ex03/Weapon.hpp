

#pragma once

#include <string>

class Weapon {
private:
    std::string type;   // silahın türü
public:
    Weapon(std::string str);
    void setType(std::string ntype);    // type değerini atamamıza sağlayacak sağlayacak.
    const std::string &getType();             // type değerini sabit referans olarak döndürecek.
    // Fonksiyonun dönüş tipi, std::string tipindeki bir nesnenin sabit (const) referansıdır. 
    // Yani fonksiyon bir string döndürür, fakat bunu referans olarak döndürür ve bu string üzerinde değişiklik yapılamaz.
    // sabit referans olarak döndürmek: Fonksiyon, bir referans döndürür; yani asıl nesnenin kendisine işaret eder, kopyasını oluşturmaz.
};
