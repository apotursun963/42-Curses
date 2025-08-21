
#include "Point.hpp"

int main(void) {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point p(2, 2);

    if (bsp(a, b, c, p) == true)
        std::cout << "İs the point inside of the triangle: True\n";
    else
        std::cout << "İs the point inside of the triangle: Flase\n";
}
