
#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int n1, int n2) : x(n1), y(n2) {}
vect2::vect2(const vect2& other) {*this = other;}
vect2& vect2::operator=(const vect2& other) {
	if(this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	return(*this);
}
vect2::~vect2() {}


int vect2::operator[](int index) const {
	if(index == 0)
		return(this->x);
	return(this->y);
}

int& vect2::operator[](int index) {
	if(index == 0)
		return(this->x);
	return(this->y);
}

/* negatif vektör
her bileşenin işaretini değiştir ve yeni bir nesne olarak döndürür.
{3, 5} → {-3, -5} döndürür
*/
vect2 vect2::operator-() const {
	vect2 temp = *this;
	temp[0] = -temp[0];
	temp[1] = -temp[1];
	return(temp);
}

/*
Bu fonksiyon, vektörü bir sayıyla çarpar ve sonucu yeni bir vektör olarak döndürür.
Yani, orijinal vektörü değiştirmez, sadece çarpılmış bir kopyasını üretir.
*/
vect2 vect2::operator*(int num) const {
	vect2 temp;
	temp.x = this->x * num;
	temp.y = this->y * num;
	return(temp);
}

// Bu fonksiyon, vektörün kendisini bir sayıyla çarpar ve sonucu kendisine geri yazar.
vect2& vect2::operator*=(int num) {
	this->x *= num;
	this->y *= num;
	return(*this);
}

vect2& vect2::operator+=(const vect2& other) {
	this->x += other.x;
	this->y += other.y;
	return(*this);
}

vect2& vect2::operator-=(const vect2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return(*this);
}

vect2& vect2::operator*=(const vect2& other) {
	this->x *= other.x;
	this->y *= other.y;
	return(*this);
}

vect2 vect2::operator+(const vect2& other) const {
	vect2 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	return(temp);
}

vect2 vect2::operator-(const vect2& other) const {
	vect2 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	return(temp);
}

vect2 vect2::operator*(const vect2& other) const {
	vect2 temp = *this;
	temp.x *= other.x;
	temp.y *= other.y;
	return(temp);
}

vect2& vect2::operator++() {
	this->x += 1;
	this->y += 1;
	return(*this);
}

vect2 vect2::operator++(int) {
	vect2 temp = *this;

	++(*this);
	return(temp);
}

vect2& vect2::operator--() {
	this->x -= 1;
	this->y -= 1;
	return(*this);
}

vect2 vect2::operator--(int) {
	vect2 temp = *this;

	--(*this);
	return(temp);
}

bool vect2::operator==(const vect2& other) const {
	if((this->x == other.x) && (this->y == other.y))
		return(true);
	return(false);
}

bool vect2::operator!=(const vect2& other) const {
	return(!(other == *this));
}

std::ostream& operator<<(std::ostream& out,const vect2& other) {
	std::cout << "{" << other[0] << ", " << other[1] << "}";
	return(out);
}

// vektörü değil, sayının solda olduğu çarpma işlemini (3 * v) mümkün kılar
vect2 operator*(int num, const vect2& other) {
	vect2 temp(other);
	temp *= num;
	return(temp);
}
