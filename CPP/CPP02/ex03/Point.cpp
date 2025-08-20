

#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const Point &other) : x(other.x), y(other.y) {

}

Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) { 

}

Point &Point::operator=(const Point &other) {
    (void)other;
    return (*this);
}

Point::~Point() { 

}


Fixed Point::GetX() {
    return this->x;
}

Fixed Point::GetY() {
    return this->y;
}

