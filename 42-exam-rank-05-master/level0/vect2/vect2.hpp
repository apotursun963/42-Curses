
#pragma once

#include <iostream>

class vect2
{
private:
	int x;
	int y;
public:
	// ortodoks
	vect2();
	vect2(int num1, int num2);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();

	// erişim operatörü	
	int operator[](int index) const;
	int& operator[](int index);

	// negatif vektör (içindeki sayıların hepsini negatif yapar)
	vect2 operator-() const;

	// skaler işlemler (sayı ile çarpma (v * 2).)
	vect2 operator*(int num) const;
	vect2& operator*=(int num);

	/* Vektörle işlemler
	+=, -=, *= → mevcut vektörü günceller.
	+, -, * → yeni bir vektör döndürür.
	Vektör versiyon → bileşen bazlı çarpma (v1 * v2).
	*/
	vect2& operator+=(const vect2& other);
	vect2& operator-=(const vect2& other);
	vect2& operator*=(const vect2& other);
	vect2 operator+(const vect2& other) const;
	vect2 operator-(const vect2& other) const;
	vect2 operator*(const vect2& other) const;

	// Artırma/Azaltma operatörleri
	vect2& operator++();
	vect2 operator++(int);
	vect2& operator--();
	vect2 operator--(int);

	// Karşılaştırma Operatörleri (eşitmi , eşit değilmi)
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;
};
vect2 operator*(int num, const vect2& other);
std::ostream& operator<<(std::ostream& out,const vect2& other);
