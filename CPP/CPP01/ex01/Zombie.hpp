/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:30:09 by atursun           #+#    #+#             */
/*   Updated: 2025/05/27 14:30:09 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
private:
    std::string name;
public:
    void announce(void);
    void setname(std::string &inname);
    
    ~Zombie();                      // destructure
};

Zombie* zombieHorde(int N, std::string name);
