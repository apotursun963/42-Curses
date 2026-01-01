
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>  // OGABKS

class bigint {
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
    bigint operator++(int);
    bigint &operator++();

    bigint operator<<(unsigned int num) const;
    bigint operator>>(unsigned int num) const;
    bigint &operator<<=(unsigned int num) ;
    bigint &operator>>=(unsigned int num) ;
    bigint operator<<(const bigint& other) const;
    bigint operator>>(const bigint& other) const;
    bigint &operator<<=(const bigint& other) ;
    bigint &operator>>=(const bigint& other) ;

    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
};
std::ostream& operator<<(std::ostream &out, const bigint& other);
