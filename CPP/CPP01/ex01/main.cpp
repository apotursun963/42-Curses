/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:05:05 by atursun           #+#    #+#             */
/*   Updated: 2025/05/24 11:05:05 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int strToInt(const std::string& s)
{
    int result = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
            return -1;
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

// std::getline(std::cin, variable);
// - std::cin: Klavyeden (standart girişten) okuma yapar.
// - variable: Okunan satırın atanacağı string değişken.

int main()
{
    PhoneBook pb;
    std::string cmd;
    pb.count = 0;
    pb.next = 0;
    while (true)
	{
        std::cout << "PhoneBook> ";
        std::getline(std::cin, cmd);
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
                std::cout << "No field can be empty!\n";
                continue;
            }
            c.set(f, l, n, p, s);
            pb.add(c);
            std::cout << "Contact added!\n";
        }
		else if (cmd == "SEARCH")
		{
            pb.list();
            std::cout << "Index to show: ";
            std::string idxStr;
            std::getline(std::cin, idxStr);
			int idx = strToInt(idxStr);
			pb.show(idx);
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Unknown command.\n";
    }
    return 0;
}
