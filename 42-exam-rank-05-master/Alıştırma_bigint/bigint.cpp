
#include "bigint.hpp"           // bigint hatalı lan
/* fatma abla şey demişti
benim repodaki bigintte shift işlemlerinde kayıdırıken 0 olduğu durumun kontrolü eksik sadece. 

1. bitsel shift operatörlerinde this->str == 0 olma durumu eksik gibi galiba hepsi için eklemen gerekiyor.
2. bool bigint::operator>(const bigint& other); fonksiyonunda mantıksal bir hata var gibi.
*/

bigint::bigint() : str("0") {}
bigint::bigint(unsigned int num) {
    std::stringstream ss;
	ss << num;
	this->str = ss.str();
}
bigint::bigint(const bigint& other) {*this = other;}
bigint &bigint::operator=(const bigint& other) {
    if (this != &other)
        this->str = other.str;
    return (*this);
}
bigint::~bigint() {}


std::string bigint::getStr() const {return (this->str);}

std::string revStr(std::string str) {
    std::string rev;
    for (size_t i=str.length(); i > 0; i--)
        rev.push_back(str[i - 1]);
    return (rev);
}

std::string addition(const bigint& other1, const bigint& other2) {
    std::string str1 = revStr(other1.getStr());
    std::string str2 = revStr(other2.getStr());
    int len1 = str1.length();
    int len2 = str2.length();
    std::string result;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff-- > 0)
            str2.push_back('0');
    }
    else if (len2 > len1) {
        int diff = len2 - len1;
        while (diff-- > 0)
            str1.push_back('0');
    }

    int carry = 0;
    int digit1, digit2;
    for (size_t i=0; i < str1.length(); i++) {
        digit1 = str1[i] - '0';
        digit2 = str2[i] - '0';
        int res = digit1 + digit2 + carry;
        if (res > 9) {
            carry = res / 10;
            result.push_back((res % 10) + '0');
        }
        else
            result.push_back(res + '0');
    }
    if (carry != 0)
        result.push_back(carry + '0');
    return (revStr(result));
}


bigint bigint::operator+(const bigint& other) const {
    bigint tmp = *this;
    tmp.str.clear();
    std::string res = addition(*this, other);
    tmp.str = res;
    return (tmp);
}

bigint &bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return (*this);
}

bigint bigint::operator++(int) {
    bigint tmp = *this;
    *this = *this + bigint(1);
    return (tmp);
}

bigint &bigint::operator++() {
    *this = *this + bigint(1);
    return (*this);
}


bigint bigint::operator<<(unsigned int num) const {
    bigint tmp = *this;
    tmp.str.insert(tmp.str.end(), num, '0');
    return (tmp);
}
bigint bigint::operator>>(unsigned int num) const {
    bigint tmp = *this;
    size_t len = tmp.str.length();
    if (num >= len)
        tmp.str = '0';
    else
        tmp.str.erase(tmp.str.length() - num, num);
    return (tmp);
}
bigint &bigint::operator<<=(unsigned int num)  {
    *this = *this << num;
    return (*this);
}
bigint &bigint::operator>>=(unsigned int num)  {
    *this = *this >> num;
    return (*this);
}

unsigned int strtouint(std::string str) {
    std::stringstream ss(str);
    unsigned int res;
    ss >> res;
    return (res);
}

bigint bigint::operator<<(const bigint& other) const {
    bigint tmp;
    tmp = *this << strtouint(other.str);
    return (tmp);
}
bigint bigint::operator>>(const bigint& other) const {
    bigint tmp;
    tmp = *this >> strtouint(other.str);
    return (tmp);
}
bigint &bigint::operator<<=(const bigint& other)  {
    *this = *this << strtouint(other.str);
    return (*this);
}
bigint &bigint::operator>>=(const bigint& other)  {
    *this = *this >> strtouint(other.str);
    return (*this);
}



bool bigint::operator==(const bigint& other) const {
    return (this->getStr() == other.getStr());
}
bool bigint::operator!=(const bigint& other) const {
    return (this->getStr() != other.getStr());
}
bool bigint::operator<(const bigint& other) const {
    std::string str1 = this->str;
    std::string str2 = other.str;
    int len1 = str1.length();
    int len2 = str2.length();
    
    if (len1 != len2)
        return (len1 < len2);
    return (str1 < str2);
}
bool bigint::operator>(const bigint& other) const {
    return (!(*this < other));
}
bool bigint::operator<=(const bigint& other) const {
    return ((*this < other) || (*this == other));
}
bool bigint::operator>=(const bigint& other) const {
    return ((*this > other) || (*this == other));
}

std::ostream& operator<<(std::ostream &out, const bigint& other) {
    out << other.getStr();
    return (out);
}
