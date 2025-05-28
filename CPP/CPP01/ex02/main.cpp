/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:43:27 by atursun           #+#    #+#             */
/*   Updated: 2025/05/27 14:43:27 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // print addresses
    std::cout << &str << std::endl;     //  memory address of the string variable.
    std::cout << stringPTR << std::endl;   //  memory address held by stringPTR
    std::cout << &stringREF << std::endl;    // memory address held by stringREF
    
    // print values
    std::cout << str << std::endl;    
    std::cout << *stringPTR << std::endl;  
    std::cout << stringREF << std::endl;    

    return 0;
}
