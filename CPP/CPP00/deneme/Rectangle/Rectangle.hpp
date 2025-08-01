
#pragma once

// 1. çözümü
class Rectangle
{
private:
    int lenght = 10;
    int height = 15;
public:
    int Rectangle_area(void)
    {
        return (lenght * height);
    }

    int Rectangle_perimeter(void)
    {
        return (2 * (lenght + height));
    }
};


// 2. çözümü
class Rectangle
{
private:
    int lenght;
    int height;
public:
    void    set(int input_lenght, int input_height);
    int     Rectangle_area(void);
    int     Rectangle_perimeter(void);
};

