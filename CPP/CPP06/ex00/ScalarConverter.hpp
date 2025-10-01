
#pragma once

#include <iostream>


class ScalarConverter {     // hepsi private olacakmışı mikail diyor ona sor
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static void    convert(std::string literal);    // literal -> Sabit değer

};
