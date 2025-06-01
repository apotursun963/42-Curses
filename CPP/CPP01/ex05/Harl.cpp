/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:49:48 by atursun           #+#    #+#             */
/*   Updated: 2025/05/31 15:33:02 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my"
                "7XL-double-cheese-triple-pickle-specialketchup burger. "
                "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money."
                "You didn’t put enough bacon in my burger!"
                "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free."
                "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*funcPtr[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string funcsname[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int  size = sizeof(funcsname) / sizeof(funcsname[0]);
    for (int i=0; i < size; i++)
    {
        if (funcsname[i] == level)
            (this->*funcPtr[i])();
    }
}
