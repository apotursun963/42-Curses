/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:23:09 by atursun           #+#    #+#             */
/*   Updated: 2025/05/31 15:25:30 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

// constructer initializer 
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
    
}

void HumanA::attack() {
    std::cout << this->name << "  attacks with their " << this->weapon.getType() << std::endl;
}
