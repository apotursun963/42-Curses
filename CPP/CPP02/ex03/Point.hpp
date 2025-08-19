
#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();


};
