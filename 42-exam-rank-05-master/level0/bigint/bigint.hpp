
#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;
		//std::string result;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& source);

		std::string getStr()const;

		bigint& operator=(const bigint& source);

		bigint operator+(const bigint& other)const;
		bigint& operator+=(const bigint& other);

		bigint& operator++(); // ++x
		bigint operator++(int); // x++

		bigint operator<<(unsigned int n)const;
		bigint operator>>(unsigned int n)const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		bigint operator<<(const bigint& other)const;
		bigint operator>>(const bigint& other)const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

		~bigint();

};
std::ostream& operator<<(std::ostream& output, const bigint& obj);
