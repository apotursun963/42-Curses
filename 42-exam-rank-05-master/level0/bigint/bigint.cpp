
#include "bigint.hpp"

bigint::bigint() : str("0") {}
bigint::bigint(unsigned int num) : str(std::to_string(num)) {}
bigint::bigint(const bigint& source) { *this = source;}
bigint& bigint::operator=(const bigint& source) {
	if (this != &source)
		this->str = source.str;
	return (*this);
}
bigint::~bigint() {}


std::string bigint::getStr() const { return (this->str); }

// stringi ters çevirir
// Bu işlem, toplama işlemini basamak basamak (sağdan sola) gerçekleştirmek için yapılır.
std::string reverse(const std::string& str) {
	std::string revStr;
	for(size_t i = str.length(); i > 0; i--)
		revStr.push_back(str[i - 1]);
	return (revStr);
}

// İki bigint nesnesini toplar ve sonucu bir dize olarak döner.
std::string addition(const bigint& obj1, const bigint& obj2) {
	std::string str1 = reverse(obj1.getStr());
	std::string str2 = reverse(obj2.getStr());
	std::string result;
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	// Uzunlukları Eşitleme
	// bir sayı diğerinden basamak (uzunluk) olarak büyükse/uzunsa
	// sonlarına sıfır eklenerek eşitlenir. Bu toplama işlemini kolaylaştırmak için yapılır
	if (len1 > len2)
	{
		int diff = len1 - len2;
		while (diff-- > 0)
			str2.push_back('0');
	}
	else if (len2 > len1)
	{
		int diff = len2 - len1;
		while (diff-- > 0)
			str1.push_back('0');
	}

	// Toplama İşlemi
	int carry = 0;  // Bir sonraki basamağa taşınacak değeri tutar.
	int digit1, digit2;
	// Döngü, dizelerin her bir basamağını toplar
	for (size_t i = 0; i < str1.length(); i++) {
		digit1 = str1[i] - '0';
		digit2 = str2[i] - '0';
		// digit1 ve digit2 toplanır, önceki basamaktan gelen carry eklenir.
		int res = digit1 + digit2 + carry;
		if (res > 9) {	// Eğer toplam 9'dan büyükse, carry hesaplanır ve toplamın birler basamağı result dizisine eklenir.
			carry = res / 10;
			result.push_back((res % 10) + '0');
		}
		else // Eğer toplam 9'dan küçükse, carry sıfırlanır ve toplam doğrudan result dizisine eklenir.
			result.push_back(res + '0');
	}
	if (carry != 0) // Döngü bittikten sonra, hala bir carry değeri varsa, bu değer result dizisine eklenir.
		result.push_back(carry + '0');
	return (reverse(result));	// sonucu ters çevirerek doğru sonuç elde edilir
}

/*
İki bigint nesnesini toplar ve sonucu döner.
*/
bigint bigint::operator+(const bigint& other) const {
	bigint temp(other);
	temp.str.clear();
	std::string result = addition(*this, other);
	temp.str = result;
	return (temp);
}

/*
Mevcut nesneye başka bir bigint ekler.
*/
bigint& bigint::operator+=(const bigint& other) {
	(*this) = (*this) + other;
	return (*this);
}

/*
Ön ek artış operatörü (++x). Nesneyi 1 artırır.
*/
bigint& bigint::operator++() {
	*(this) = *(this) + bigint(1);
	return(*this);
}

/*
Son ek artış operatörü (x++). Nesneyi 1 artırır, ancak önceki değeri döner.
*/
bigint bigint::operator++(int) {
	bigint temp = (*this);
	*(this) = *(this) + bigint(1);
	return(temp);
}

/*
bigint nesnesinin değerini sola kaydırır. 
Ancak, bu işlem bit düzeyinde değil, sayının sonuna n adet 0 ekleyerek gerçekleştirilir
kısacası, "123" değeri var ve n = 2
sonuç: 12300 olur
*/
bigint bigint::operator<<(unsigned int n) const {
	bigint temp = *this;

	temp.str.insert(temp.str.end(), n, '0'); // tmp'nin sonuna n adet 0 eklendir
	return (temp);
}

/*
Bu fonksiynda aynı şekilde bigint nesnesininin değerini
n kadar sağa kaydırır. 
Ancak, bu işlem bit düzeyinde değil, 
sayının sonundan n adet karakter silerek gerçekleştirilir.
*/
bigint bigint::operator>>(unsigned int n) const {
	bigint temp = *this;
	size_t len = temp.str.length();
	if(n >= len) // Eğer n, sayının uzunluğundan büyük veya eşitse, sayı tamamen silinir ve "0" yapılır.
		temp.str = "0";
	else
		temp.str.erase(temp.str.length() - n, n); // ilk parametre: silme yapacağın yerin başlangıç indexi, diğeri: kaç tane eleman silinecek
	return (temp);
}

// Bu fonksiyon, mevcut nesneyi sola kaydırır ve sonucu doğrudan mevcut nesneye atar.
bigint& bigint::operator<<=(unsigned int n) {
	(*this) = (*this) << n;	// << operatörü çağırılıyor (yukarda)
	return (*this);
}

// Bu fonksiyon, mevcut nesneyi sağa kaydırır ve sonucu doğrudan mevcut nesneye atar.
bigint& bigint::operator>>=(unsigned int n) {
	(*this) = (*this) >> n;
	return (*this);
}

// Bir stringi unsigned int türüne çevirir.
unsigned int stringToUINT(std::string str) {
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

/*
Bu fonksiyon, bir bigint nesnesini başka bir bigint nesnesi kadar sola kaydırır.
- other nesnesinin str değeri unsigned int'e dönüştürülür.
- << operatörü çağrılarak mevcut nesne sola kaydırılır.
*/
bigint bigint::operator<<(const bigint& other) const {
	bigint temp;
	temp = (*this) << stringToUINT(other.str);
	return(temp);
}

/*
Bu fonksiyon, bir bigint nesnesini başka bir bigint nesnesi kadar sağa kaydırır.
- other nesnesinin str değeri unsigned int'e dönüştürülür.
- >> operatörü çağrılarak mevcut nesne sağa kaydırılır.
*/
bigint bigint::operator>>(const bigint& other) const {
	bigint temp;
	temp = (*this) >> stringToUINT(other.str);
	return(temp);
}

/*
Bu fonksiyon, mevcut nesneyi başka bir bigint nesnesi kadar sola kaydırır ve sonucu mevcut nesneye atar.
- << operatörü çağırılır
- güncellenmiş nesene döndürülür
*/
bigint& bigint::operator<<=(const bigint& other) {
	(*this) = (*this) << stringToUINT(other.str);
	return(*this);
}

/*
Bu fonksiyon, mevcut nesneyi başka bir bigint nesnesi kadar sağa kaydırır ve sonucu mevcut nesneye atar.
- >> operatörü çağırılır
- güncellenmiş nesene döndürülür
*/
bigint& bigint::operator>>=(const bigint& other) {
	(*this) = (*this) >> stringToUINT(other.str);
	return (*this);
}


bool bigint::operator==(const bigint& other) const {
	return (this->getStr() == other.getStr());
}

bool bigint::operator!=(const bigint& other) const {
	return (this->getStr() != other.getStr());
}

// Bu fonksiyon, bir bigint nesnesinin diğerinden küçük olup olmadığını kontrol eder.
bool bigint::operator<(const bigint& other) const {
	std::string str1 = this->str;
	std::string str2 = other.getStr();
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	if (len1 != len2)
		return (len1 < len2);
	return (str1 < str2);  //  Eğer uzunluklar eşitse, std::string'in < operatörü kullanılarak alfabetik sıralama yapılır.
}

// < operatörü çağırılarak this nesnesinin küçük olup olmadığı kontrol edilir
bool bigint::operator>(const bigint& other) const {
	return(!(*this < other));
}

// Bu fonksiyon, bir bigint nesnesinin diğerine küçük eşit olup olmadığını kontrol eder.
// < ve == operatörleri çağırılır
bool bigint::operator<=(const bigint& other) const {
	return (((*this < other) || (*this == other)));
}

// Bu fonksiyon, bir bigint nesnesinin diğerine büyük eşit olup olmadığını kontrol eder
// > ve == operatörleri çağırılır
bool bigint::operator>=(const bigint& other) const {
	return (((*this > other) || (*this == other)));
}

std::ostream& operator<<(std::ostream& output, const bigint& obj) {
	output << obj.getStr();
	return(output);
}
