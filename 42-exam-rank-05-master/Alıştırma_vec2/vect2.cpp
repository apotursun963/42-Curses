
#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int x, int y) : x(x), y(y) {}
vect2::vect2(const vect2& other) {*this = other;}
vect2 &vect2::operator=(const vect2& other) {
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return (*this);
}
vect2::~vect2() {};

int &vect2::operator[](int idx) {
    if (idx == 0)
        return (this->x);
    return (this->y);
}

int vect2::operator[](int idx) const {
    if (idx == 0)
        return (this->x);
    return (this->y);
}


vect2 &vect2::operator++() {
    this->x += 1;
    this->y += 1;
    return (*this);
}

vect2 vect2::operator++(int) {
    vect2 tmp = *this;

    ++(*this);
    return (tmp);
}

vect2 &vect2::operator--() {
    this->x -= 1;
    this->y -= 1;
    return (*this);
}

vect2 vect2::operator--(int) {
    vect2 tmp = *this;

    --(*this);
    return (tmp);
}


vect2 &vect2::operator+=(const vect2& other) {
    this->x += other[0];
    this->y += other[1];
    return (*this);
}

vect2 &vect2::operator-=(const vect2& other) {
    this->x -= other[0];
    this->y -= other[1];
    return (*this);
}

vect2 &vect2::operator*=(const vect2& other) {
    this->x *= other[0];
    this->y *= other[1];
    return (*this);
}

vect2 vect2::operator+(const vect2& other) const {
    vect2 tmp = *this;
    tmp.x += other[0];
    tmp.y += other[1];
    return (tmp);
}

vect2 vect2::operator-(const vect2& other) const {
    vect2 tmp = *this;
    tmp.x -= other[0];
    tmp.y -= other[1];
    return (tmp);
}


vect2 vect2::operator*(const vect2& other) const {
    vect2 tmp = *this;
    tmp.x *= other[0];
    tmp.y *= other[1];
    return (tmp);
}

vect2 vect2::operator*(int num) const {
    vect2 tmp = *this;
    tmp.x *= num;
    tmp.y *= num;
    return (tmp);
}

vect2 &vect2::operator*=(int num) {
    this->x *= num;
    this->y *= num;
    return (*this);
}

vect2 operator*(int num, const vect2& other) {
    vect2 tmp(other);
    tmp *= num;
    return (tmp);
}

vect2 vect2::operator-() const {
    vect2 tmp = *this;
    tmp[0] = -tmp[0];
    tmp[1] = -tmp[1];
    return (tmp);
}


bool vect2::operator==(const vect2& other) const {
    if ((this->x == other.x) && (this->y) == other.y)
        return (true);
    return (false);
}

bool vect2::operator!=(const vect2& other) const {
    if ((this->x == other.x) && (this->y) == other.y)
        return (false);
    return (true);
}



std::ostream& operator<<(std::ostream &out, const vect2& other) {
    std::cout << "{" << other[0] << ", " << other[1] << "}";
    return (out);
}
