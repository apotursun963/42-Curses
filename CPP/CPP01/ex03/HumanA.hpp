/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:20:41 by atursun           #+#    #+#             */
/*   Updated: 2025/05/30 16:35:23 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon &weapon;
public:
    HumanA(std::string name, Weapon &weapon);
	~HumanA();
    void attack();
};
