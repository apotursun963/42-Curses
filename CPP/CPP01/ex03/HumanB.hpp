/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:26:12 by atursun           #+#    #+#             */
/*   Updated: 2025/05/30 17:16:44 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *weapon;
public:
	HumanB(std::string name);
	~HumanB();
    void setWeapon(Weapon &weapon);
    void attack();
};

/*
HumanA: Silahı referans ile alır, yani silahsız olamaz ve silahı sonradan değiştirilemez.
(başka bir silaha atanamaz, ama silahın tipi değişirse etkilenir).
HumanB: Silahı işaretçi ile tutar, başlangıçta silahsız olabilir ve istediği zaman silah atanabilir.

Referans ile işaretçi farkı: Referanslar her zaman bir nesneye bağlıdır ve sonradan başka bir nesneye bağlanamaz.
İşaretçiler ise null olabilir ve istendiğinde başka bir nesneyi gösterebilir.
*/
