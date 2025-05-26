/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:48:57 by atursun           #+#    #+#             */
/*   Updated: 2025/05/07 16:20:35 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        while (argv[i])
        {
            int j = 0;
            while (argv[i][j])
            {
                std::cout << (char) std::toupper(argv[i][j]);
                j++;
            }
            std::cout << " ";
            i++;
        }
        std::cout << "\n";
    }
    return 0;
}
