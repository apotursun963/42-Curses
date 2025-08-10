
#include "Person.hpp"

Person::Person() : name("Unknown"), country("USA"), age(19) { }

Person::Person(std::string input_name, std::string input_country, int input_age)
{
    this->name = input_name;
    this->country = input_country;
    this->age = input_age;
}

std::string Person::get_name(void)
{
    return (this->name);
}

std::string Person::get_country(void)
{
    return (this->country);
}

int Person::get_age(void)
{
    return (this->age);
}

