

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>
#include <stdexcept>

class ScalarConverter {
public:
    static void convert(const std::string& literal) {
        if (isChar(literal))
            charConvert(literal);
        else if (isInt(literal))
            intConvert(literal);
        else if (isFloat(literal))
            floatConvert(literal);
        else if (isDouble(literal))
            doubleConvert(literal);
        else if (isPseudoLiteral(literal))
            pseudoLiteralConvert(literal);
        else
            printImpossible();
    }

private:
    // Kontroller
    static bool isChar(const std::string& s) {
        return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
    }

    static bool isInt(const std::string& s) {
        size_t i = 0;
        if (s.empty()) return false;
        if (s[0] == '+' || s[0] == '-') i++;
        if (i == s.size()) return false;
        for (; i < s.size(); ++i)
            if (!std::isdigit(s[i]))
                return false;
        return true;
    }

    static bool isFloat(const std::string& s) {
        if (s == "+inff" || s == "-inff" || s == "nanf") return true;
        size_t len = s.length();
        if (len < 2 || s[len - 1] != 'f') return false;

        bool point_found = false;
        size_t i = 0;
        if (s[0] == '+' || s[0] == '-') i++;

        for (; i < len -1; ++i) {
            if (s[i] == '.') {
                if (point_found) return false;
                point_found = true;
            }
            else if (!std::isdigit(s[i])) return false;
        }
        return point_found;
    }

    static bool isDouble(const std::string& s) {
        if (s == "+inf" || s == "-inf" || s == "nan") return true;
        size_t len = s.length();
        if (len < 1) return false;

        bool point_found = false;
        size_t i = 0;
        if (s[0] == '+' || s[0] == '-') i++;

        for (; i < len; ++i) {
            if (s[i] == '.') {
                if (point_found) return false;
                point_found = true;
            }
            else if (!std::isdigit(s[i])) return false;
        }
        return point_found;
    }

    static bool isPseudoLiteral(const std::string& s) {
        return s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff";
    }

    // Dönüşümler ve yazdırma

    static void charConvert(const std::string& s) {
        char c = s[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }

    static void intConvert(const std::string& s) {
        try {
            int n = std::stoi(s);
            printCharFromInt(n);
            printInt(n);
            printFloat(static_cast<float>(n));
            printDouble(static_cast<double>(n));
        }
        catch (...) {
            printImpossible();
        }
    }

    static void floatConvert(const std::string& s) {
        try {
            float f = std::stof(s);
            printCharFromFloat(f);
            printInt(static_cast<int>(f));
            printFloat(f);
            printDouble(static_cast<double>(f));
        }
        catch (...) {
            printImpossible();
        }
    }

    static void doubleConvert(const std::string& s) {
        try {
            double d = std::stod(s);
            printCharFromDouble(d);
            printInt(static_cast<int>(d));
            printFloat(static_cast<float>(d));
            printDouble(d);
        }
        catch (...) {
            printImpossible();
        }
    }

    static void pseudoLiteralConvert(const std::string& s) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";

        if (s == "nan" || s == "nanf") {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
        else if (s == "+inf" || s == "+inff") {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        else if (s == "-inf" || s == "-inff") {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
    }

    // Yardımcı yazdırma fonksiyonları

    static void printChar(char c) {
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }

    static void printCharFromInt(int n) {
        if (n < 0 || n > 127)
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(n));
    }

    static void printCharFromFloat(float f) {
        if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(f));
    }

    static void printCharFromDouble(double d) {
        if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(d));
    }

    static void printInt(int n) {
        std::cout << "int: " << n << '\n';
    }

    static void printFloat(float f) {
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
    }

    static void printDouble(double d) {
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << '\n';
    }

    static void printImpossible() {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
};
