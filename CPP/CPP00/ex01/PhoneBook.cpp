
#include "PhoneBook.hpp"

void PhoneBook::add(Contact& c)
{
    contacts[next % 8] = c;
    next++;
    if (count < 8)
        count++;
}

void PhoneBook::list()
{
    if (count == 0)
        return ;
    std::cout << "| Index |First Name| Last Name| Nick Name|" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < count; ++i)
    {
        std::cout << "| " << std::setw(5) << i << " ";
        printField(contacts[i].getFirstName());
        printField(contacts[i].getLastName());
        printField(contacts[i].getNickName());
        std::cout << "|" << std::endl;
    }
}

void PhoneBook::show(int i)
{
    if (i < 0 || i >= count)
    {
        std::cout << "Invalid index!" << std::endl;
        return ;
    }
    std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nick Name: " << contacts[i].getNickName() << std::endl;
    std::cout << "Phone:     " << contacts[i].getPhone() << std::endl;
    std::cout << "Secret:    " << contacts[i].getSecret() << std::endl;
}

void PhoneBook::printField(std::string str)
{
    if (str.length() > 10)
        std::cout << "|" << str.substr(0, 9) << ".";
    else
        std::cout << "|" << std::setw(10) << str;
}
