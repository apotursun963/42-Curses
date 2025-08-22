
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

    Point(const float x, const float y);

    Fixed GetX();
    Fixed GetY();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);