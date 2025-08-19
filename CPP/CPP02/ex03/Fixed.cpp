
// Yorumları silecekmisin yoksa kalacakmı iyice öğren (subjecte daha okunabilir olması için sildini diyorda bir bak)
#include "Fixed.hpp"

// Bu tam sayıyı, sabit noktalı (fixed-point) formata çevirsin.
Fixed::Fixed(const int num_int) : fixed_point_value(num_int << fraction) {	// yada num_int * 256
	// std::cout << "Int constructor called\n";
}

// Bu ondalıklı sayıyı sabit noktalı formata çevirsin.
Fixed::Fixed(const float num_flo) : fixed_point_value(int(roundf(num_flo * (1 << fraction)))) {
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed() : fixed_point_value(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixed_point_value(other.fixed_point_value) {
  // std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());   // Değeri kopyala
    return *this;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (fixed_point_value);
}

void Fixed::setRawBits(const int raw) {
  fixed_point_value = raw;
}

int Fixed::toInt(void) const {
	return (int(fixed_point_value >> fraction));		// yada (fixed_sayi / 256)
}

float Fixed::toFloat(void) const {
	return (float(fixed_point_value) / (1 << fraction));
}


bool Fixed::operator>(const Fixed &other) const {
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed &other) const {
    return this->toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed &other) const {
    return this->toFloat() - other.toFloat();
}

Fixed Fixed::operator*(const Fixed &other) const {
    return this->toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed &other) const {
    return this->toFloat() / other.toFloat();
}

/*
| Operatör | Kullanım | Önce mi sonra mı artar/azalır | Dönen    | Notlar                 |
| -------- | -------- | ----------------------------- | -------- | ---------------------- |
| `++a`    | Pre-inc  | Önce artar                    | Referans | Zincirlenebilir        |
| `a++`    | Post-inc | Sonra artar                   | Kopya    | Önceki değeri döndürür |
| `--a`    | Pre-dec  | Önce azalır                   | Referans | Zincirlenebilir        |
| `a--`    | Post-dec | Sonra azalır                  | Kopya    | Önceki değeri döndürür |
*/
Fixed &Fixed::operator++() {
	this->fixed_point_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed duplicated(*this);
	operator++();
	return (duplicated);
}

Fixed &Fixed::operator--() {
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed duplicated(*this);
	operator--();
	return (duplicated);
}

/*
| Fonksiyon                           | Parametre | Dönen          | Notlar                            |
| ----------------------------------- | --------- | -------------- | --------------------------------- |
| `min(Fixed &, Fixed &)`             | Non-const | Referans       | Döndürülen nesne değiştirilebilir |
| `min(const Fixed &, const Fixed &)` | Const     | Const referans | Döndürülen nesne değiştirilemez   |
| `max(Fixed &, Fixed &)`             | Non-const | Referans       | Döndürülen nesne değiştirilebilir |
| `max(const Fixed &, const Fixed &)` | Const     | Const referans | Döndürülen nesne değiştirilemez   |
*/
Fixed &Fixed::min(Fixed &Fixed1, Fixed &Fixed2) {
    if (Fixed1 < Fixed2)
        return (Fixed1);
    return (Fixed2);
}

const Fixed &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2) {
    if (Fixed1 < Fixed2)
        return (Fixed1);
    return (Fixed2);
}

Fixed &Fixed::max(Fixed &Fixed1, Fixed &Fixed2) {
	if (Fixed1 > Fixed2)
		return (Fixed1);
	return (Fixed2);
}

const Fixed &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2) {
	if (Fixed1 > Fixed2)
		return (Fixed1);
	return (Fixed2);
}


// Bu bir operatör overload fonksiyonudur.
/*
Dönüş tipi: std::ostream&
- Akışın (stream) kendisinin referansını geri döndürür.
- Amaç: zincirleme (chaining) yapılabilsin diye. Örn: std::cout << a << " " << b;
Fonksiyon adı: operator<<
- Bu bir “insertion” (ekleme/yazdırma) operatörü aşırı yüklemesi.
İlk parametre: std::ostream &out
- Sol taraftaki akış nesnesi buraya bağlanır. “std::cout << a” yazdığında cout bu parametreye düşer.
- Referans olarak alınır (kopyalamak mantıksız ve pahalı, ayrıca akışın durumu değişecek).
İkinci parametre: const Fixed &right
- Sağ taraftaki nesnen (a) buraya bağlanır.
- const &: Kopya maliyetinden kaçınmak ve yazdırma sırasında nesneyi değiştirmeyeceğini garanti etmek için.

*/
std::ostream &operator<<(std::ostream &out, const Fixed &right) {
	out << right.toFloat();
	return (out);    // zincirleme yapabilsin diye return ediyoruz
}
