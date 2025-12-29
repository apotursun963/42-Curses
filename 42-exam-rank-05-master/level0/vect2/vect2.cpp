
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
Bu fonksiyon, vektörü bir sayıyla (skaler) çarpar ve sonucu yeni bir vektör olarak döndürür.
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


// İki vect2 nesnesini toplar ve sonucu mevcut nesneye (this) yazar.
vect2& vect2::operator+=(const vect2& other) {
	this->x += other.x;
	this->y += other.y;
	return(*this);
}

// İki vect2 nesnesini çıkarır ve sonucu mevcut nesneye (this) yazar.
vect2& vect2::operator-=(const vect2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return(*this);
}

// İki vect2 nesnesinin bileşenlerini çarpar ve sonucu mevcut nesneye (this) yazar.
vect2& vect2::operator*=(const vect2& other) {
	this->x *= other.x;
	this->y *= other.y;
	return(*this);
}

// İki vect2 nesnesini toplar ve sonucu yeni bir vect2 nesnesi olarak döndürür.
vect2 vect2::operator+(const vect2& other) const {
	vect2 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	return(temp);
}

// İki vect2 nesnesini çıkarır ve sonucu yeni bir vect2 nesnesi olarak döndürür.
vect2 vect2::operator-(const vect2& other) const {
	vect2 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	return(temp);
}

// İki vect2 nesnesini çarpar ve sonucu yeni bir vect2 nesnesi olarak döndürür.
vect2 vect2::operator*(const vect2& other) const {
	vect2 temp = *this;
	temp.x *= other.x;
	temp.y *= other.y;
	return(temp);
}


/* Prefix arttırma (++V)
Vektörün her iki bileşenini (x ve y) birer artırır.
Çalışma şekli:
	- this->x ve this->y değerleri birer artırılır.
	- Artırılmış haliyle *this (yani mevcut nesne) döndürülür.
Önce artırma işlemi yapılır, ardından artırılmış nesne döndürülür.
*/
vect2& vect2::operator++() {
	this->x += 1;
	this->y += 1;
	return(*this);
}

/* Postfix arttırma (V++)
Vektörün her iki bileşenini birer artırır, ancak artırmadan önceki hali döndürür.
Çalışma şekli:
	- Mevcut nesnenin bir kopyası (temp) oluşturulur.
	- Prefix artırım (++(*this)) çağrılarak mevcut nesne artırılır.
	- Artırmadan önceki hali (temp) döndürülür.
Önce mevcut nesne döndürülür, ardından artırma işlemi yapılır.
*/
vect2 vect2::operator++(int) {
	vect2 temp = *this;

	++(*this);
	return(temp);
}

/* Prefix Azaltım (--V)
Vektörün her iki bileşenini (x ve y) birer azaltır.
Çalışma şekli:
	- this->x ve this->y değerleri birer azaltılır.
	- Azaltılmış haliyle *this döndürülür.
Önce azaltma işlemi yapılır, ardından azaltılmış nesne döndürülür
*/
vect2& vect2::operator--() {
	this->x -= 1;
	this->y -= 1;
	return(*this);
}

/* Postfix Azaltım (V++)
Vektörün her iki bileşenini birer azaltır, ancak azaltmadan önceki hali döndürür.
Çalışma şekli:
	- Mevcut nesnenin bir kopyası (temp) oluşturulur.
	- Prefix azaltım (--(*this)) çağrılarak mevcut nesne azaltılır.
	- Azaltmadan önceki hali (temp) döndürülür
Önce mevcut nesne döndürülür, ardından azaltma işlemi yapılır.
*/
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
