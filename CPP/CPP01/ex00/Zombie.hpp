/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:09:47 by atursun           #+#    #+#             */
/*   Updated: 2025/05/27 14:09:47 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
private:
    std::string name;
public:
    void announce(void);

    Zombie(std::string &inname);    // constructure
    ~Zombie();                      // destructure
};

Zombie* newZombie(std::string name);    // This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
void randomChump(std::string name);     // This function creates a zombie, names it, and makes it announce itself 
