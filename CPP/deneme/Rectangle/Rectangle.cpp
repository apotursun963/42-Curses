

#include "Rectangle.hpp"

void Rectangle::set(int input_lenght, int input_height)
{
    this->lenght = input_lenght;
    this->height = input_height;
}

int Rectangle::Rectangle_area(void)
{
    return (this->lenght * this->height);
}

int Rectangle::Rectangle_perimeter(void)
{
    return (2 * (this->lenght + this->height));
}
