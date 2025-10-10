
#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include <string>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {     // hepsi private olacakmış mikail diyor ona göre
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void    convert(std::string literal);    // literal -> Sabit değer
};
