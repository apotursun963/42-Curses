



#include "Rectangle.hpp"
#include <iostream>

// 1. çözümü
int main(int argc, char const *argv[])
{
    Rectangle Rec;

    int area = Rec.Rectangle_area();
    int perimeter = Rec.Rectangle_perimeter();

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}


// 2. çözümü
int main(int argc, char const *argv[])
{
    Rectangle Rec;

    Rec.set(10, 15);

    int area = Rec.Rectangle_area();
    int perimeter = Rec.Rectangle_perimeter();

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}
