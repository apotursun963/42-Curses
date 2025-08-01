

/*
Person adında bir sınıf oluşturan C++ programı yazın. Bu sınıf aşağıdaki özelliklere sahip olmalıdır:

Private üye değişkenleri: name (string), age (int), country (string)
Constructor: Parametreli constructor ve default constructor
Getter ve Setter fonksiyonları: Tüm private değişkenler için

*/


#pragma once

#include <iostream>

class Person
{
private:
    std::string name;
    std::string country;
    int         age;

public:
    Person();   // Default constructor
    Person(std::string input_name, std::string input_country, int input_age);   // Parametreli/inputlu constructor

    // getter
    std::string get_name(void);
    std::string get_country(void);
    int         get_age(void);
};


