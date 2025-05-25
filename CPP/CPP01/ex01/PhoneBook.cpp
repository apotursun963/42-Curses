/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:05:07 by atursun           #+#    #+#             */
/*   Updated: 2025/05/24 11:05:07 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>


/*
Yeni bir kişi ekler.
Kişi, contacts[next] konumuna eklenir.
next bir sonraki konuma geçer (8'e ulaşınca başa döner).
Eğer rehberde 8'den az kişi varsa, kişi sayısı artırılır.
*/
void PhoneBook::add(Contact& c)
{
    contacts[next] = c;
    next = (next + 1) % 8;
    if (count < 8)
        count++;
}

void PhoneBook::list()
{
    std::cout << "| Index |First Name| Last Name| Nick Name|\n";
    std::cout << "------------------------------------------\n";
    for (int i = 0; i < count; ++i)
    {
        std::cout << "| " << std::setw(5) << i << " ";  // Kişiler listelenirken sütunlar hizalı olsun diye std::setw kullanılı
        printField(contacts[i].getFirstName());
        printField(contacts[i].getLastName());
        printField(contacts[i].getNickName());
        std::cout << "|\n";
    }
}

void PhoneBook::show(int i)
{
    if (i < 0 || i >= count)
    {
        std::cout << "Invalid index!\n";
        return ;
    }
    std::cout << "First Name: " << contacts[i].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[i].getLastName() << "\n";
    std::cout << "Nick Name: " << contacts[i].getNickName() << "\n";
    std::cout << "Phone:     " << contacts[i].getPhone() << "\n";
    std::cout << "Secret:    " << contacts[i].getSecret() << "\n";
}

int PhoneBook::size() { return count; }

void PhoneBook::printField(std::string str)
{
    if (str.length() > 10)
        std::cout << "|" << str.substr(0, 9) << ".";
    else
        std::cout << "|" << std::setw(10) << str;
}
