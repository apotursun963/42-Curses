/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:13:21 by atursun           #+#    #+#             */
/*   Updated: 2025/05/30 16:33:14 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon(std::string str);
    ~Weapon();
    std::string &getType();
    void setType(std::string ntype);
};

