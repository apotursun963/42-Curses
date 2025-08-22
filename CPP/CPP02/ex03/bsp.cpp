

#include "Point.hpp"


float arTriangle(Point a, Point b, Point c) {
    float x0 = a.GetX().toFloat();
    float x1 = b.GetX().toFloat();
    float x2 = c.GetX().toFloat();

    float y0 = a.GetY().toFloat();
    float y1 = b.GetY().toFloat();
    float y2 = c.GetY().toFloat();

    return fabs((x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float totalArea = arTriangle(a, b, c);
    float ar1 = arTriangle(a, b, point); 
    float ar2 = arTriangle(a, c, point); 
    float ar3 = arTriangle(c, b, point);

    if (ar1 == 0 || ar2 == 0 || ar3 == 0)
        return (false);

    return ((ar1 + ar2 + ar3) == totalArea);
}
