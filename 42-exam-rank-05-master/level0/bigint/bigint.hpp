
#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint { // OGABKS
private:
	std::string str;
public:
	bigint();
	bigint(unsigned int num);
	bigint(const bigint& source);
	bigint &operator=(const bigint& source);
	~bigint();

	std::string getStr() const;

	// Aritmetik operatörler
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);
	bigint& operator++(); // ++x
	bigint operator++(int); // x++

	// Bit kaydırma operatörleri
	/*
	2 ye ayrılır
	n ve other parametreli olanlar
	sonrasında 4 tane opeatör vardır
	= olmayan operatörlerde const vardır
	*/
	bigint operator<<(unsigned int n) const;
	bigint operator<<(const bigint& other) const;
	bigint operator>>(unsigned int n) const;
	bigint operator>>(const bigint& other) const;
	bigint& operator<<=(unsigned int n);
	bigint& operator<<=(const bigint& other);
	bigint& operator>>=(unsigned int n);
	bigint& operator>>=(const bigint& other);

	// Karşılaştırma Operatörleri
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
};
std::ostream& operator<<(std::ostream& output, const bigint& obj);
