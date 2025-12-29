
/*
önemli not
eğer funcs protopin sonunda const varsa demekki mevcut nesne/obje (this) üzerinde 
değer güncelleyemezsin. o zaman hemen kopyasını (tmp) oluşturup onun üzerinde işlem yapman gerekiyor
ve bazende tmp döndürmen gerekiyor
eğer const yoksa ise o zaman mevcut obje üzerinde değer güncelleyebilirsin ve bu seferde 
tmp/copy nesne oluşturmana gerek kalmaz. direkt olarak this üzerinden işlemler yapılabilir.
*/

#pragma once
#include <iostream>

class vect2 {

private:
    int x;
    int y;
public:
    vect2();
    vect2(int x, int y);
    vect2(const vect2& other);
    vect2 &operator=(const vect2& other);
    ~vect2();

    int operator[](int idx) const;
    int& operator[](int idx);

    vect2 operator++(int);
    vect2 &operator++();
    vect2 operator--(int);
    vect2 &operator--();

    vect2 &operator+=(const vect2& other);
    vect2 &operator-=(const vect2& other);
    vect2 &operator*=(const vect2& other);
    vect2 operator+(const vect2& other) const;
    vect2 operator-(const vect2& other) const;
    vect2 operator*(const vect2& other) const;

    vect2 operator*(int num) const;
    vect2 &operator*=(int num);

    vect2 operator-() const;

    bool operator==(const vect2& other) const;
    bool operator!=(const vect2& other) const;

};
vect2 operator*(int num, const vect2& other);
std::ostream& operator<<(std::ostream &out, const vect2& other);
