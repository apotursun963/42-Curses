
#pragma once

#include <iostream>
#include <sstream>

class bigint {  // OGABKS
private:
    std::string str;
public:
    bigint();
    bigint(unsigned int num);
    bigint(const bigint& other);
    bigint &operator=(const bigint& other);
    ~bigint();

    std::string getStr() const;

    bigint operator+(const bigint& other) const;
    bigint &operator+=(const bigint& other);
    bigint &operator++();
    bigint operator++(int);

    bigint operator<<(unsigned int n) const;
    bigint operator>>(unsigned int n) const;
    bigint &operator<<=(unsigned int n);
    bigint &operator>>=(unsigned int n);
    bigint operator<<(const bigint& other) const;
    bigint operator>>(const bigint& other) const;
    bigint &operator<<=(const bigint& other);
    bigint &operator>>=(const bigint& other);

    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
};
std::ostream &operator<<(std::ostream &out, const bigint& other);

