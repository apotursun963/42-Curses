
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"

int main()
{
    PhoneBook pb;
    std::string cmd;
    pb.count = 0;
    pb.next = 0;
    while (true)
	{
        std::cout << GREEN"PhoneBook> "RESET;
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            return 0;
        if (cmd == "ADD")
		{
            Contact c;
            std::string f, l, n, p, s;
            std::cout << "First Name: ";   std::getline(std::cin, f);
            std::cout << "Last Name: ";    std::getline(std::cin, l);
            std::cout << "Nick Name: ";    std::getline(std::cin, n);
            std::cout << "Phone: ";        std::getline(std::cin, p);
            std::cout << "Secret: ";       std::getline(std::cin, s);
            if (f.empty() || l.empty() || n.empty() || p.empty() || s.empty())
			{
                std::cout << "No field can be empty!" << std::endl;
                continue;
            }
            c.set(f, l, n, p, s);
            pb.add(c);
            std::cout << "Contact added!" << std::endl;
        }
		else if (cmd == "SEARCH")
		{
            if (pb.count != 0)
            {
                pb.list();
                std::cout << "Index to show: ";
                std::string idxStr;
                std::getline(std::cin, idxStr);
                int idx = idxStr[0] - 48;
                if (!idxStr[1])
                    pb.show(idx);
            }
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Unknown command" << std::endl;
    }
    return 0;
}
