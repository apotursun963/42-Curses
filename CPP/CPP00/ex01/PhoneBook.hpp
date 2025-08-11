
#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
    Contact contacts[8];
    void printField(std::string);
public:
    int count;
    int next;

    void add(Contact&);
    void list();
    void show(int);
};
