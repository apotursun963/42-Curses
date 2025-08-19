

#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const Point &other) : x(other.x), y(other.y) { }

Point &Point::operator=(const Point &other) {
    if (this != &other)
        
}