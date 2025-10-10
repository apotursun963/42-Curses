

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return (*this);}


void    Int_Convert(std::string literal) {
    int num = atoi(literal.c_str());

    if (num < 0 || num > 127)
        std::cout << "char: impossible\n";
    else {
        if (std::isprint(static_cast<char>(num)))
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void    Char_Convert(std::string literal) {
    char chr = literal[0];

    if (std::isprint(chr))
        std::cout << "char: '" << chr << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(chr) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(chr) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(chr) << std::endl;
}

void    Float_Convert(std::string literal) {
    float num = atof(literal.c_str());

    if (num < 0 || num > 127)
        std::cout << "char: impossible\n";
    else {
        if (std::isprint(static_cast<char>(num)))
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void    Float_Double(std::string literal) {
    double num = atof(literal.c_str());

    if (num < 0 || num > 127)
        std::cout << "char: impossible\n";
    else {
        if (std::isprint(static_cast<char>(num)))
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}

void    pseudo_literal(std::string literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}


bool is_Int(std::string param) {
    size_t i = 0;
    if (param.empty())
        return (false);
    if (param[0] == '-' || param[0] == '+')
        i = 1;
    if (i == param.size())
        return (false);
    while (i < param.size()) {
        if (!isdigit(param[i]))
            return (false);
        i++;
    }
    return (true);
}

bool is_Char(std::string param) {
    if (param.length() == 1
    && std::isprint(param[0])
    && !std::isdigit(param[0]))
        return (true);
    return (false);
}


bool is_Float(std::string param) {
    size_t len_param = param.length();
    if (param[len_param -1] != 'f' || len_param < 2)
        return (false);
    int is_there_dot = 0;
    size_t j = 0;
    if (param[0] == '+' || param[0] == '-')
        j = 1;
    while (j < param.length() - 1) {    // -1 f'yi dahil etmemesi gerekiyor
        if (param[j] == '.') {
            if (is_there_dot == 1)
                return (false);
            is_there_dot = 1;
        }
        else if (!std::isdigit(param[j]))
            return (false);
        j++;
    }
    return (is_there_dot);
}

bool is_Double(std::string param) {
    size_t len_param = param.length();
    if (len_param < 1)
        return (false);
    int is_there_dot = 0;
    size_t j = 0;
    if (param[0] == '+' || param[0] == '-')
        j = 1;
    while (j < param.length()) {
        if (param[j] == '.') {
            if (is_there_dot == 1)
                return (false);
            is_there_dot = 1;
        }
        else if (!std::isdigit(param[j]))
            return (false);
        j++;
    }
    return (is_there_dot);
}

bool    is_pseudo(std::string param) {
    if (param == "+inff" || param == "-inff" || param == "nanf"
    || param == "+inf" || param == "-inf" || param == "nan")
        return (true);
    return (false);
}

void    impossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string literal) {
    if (is_pseudo(literal))
        pseudo_literal(literal);
    else if (is_Int(literal))
        Int_Convert(literal);
    else if (is_Char(literal))
        Char_Convert(literal);
    else if (is_Float(literal))
        Float_Convert(literal);
    else if (is_Double(literal))
        Float_Double(literal);
    else
        impossible();        
}
