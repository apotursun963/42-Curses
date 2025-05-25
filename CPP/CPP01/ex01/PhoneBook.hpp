/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:05:09 by atursun           #+#    #+#             */
/*   Updated: 2025/05/24 11:05:09 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];	// 8 kişilik bir dizi
    static void printField(std::string);  // Bir alanı (örneğin isim, soyisim) ekrana düzgün biçimde yazdırmak için kullanılan yardımcı fonksiyon.
public:
    int count;				// Şu anda rehberde kaç kişi olduğunu tutar.
    int next;				// Yeni bir kişi ekleneceğinde hangi dizin kullanılacak onu gösterir (dairesel ekleme için kullanılır).
    
    void add(Contact&);	// Yeni bir kişi ekler. Eğer 8 kişilik yer doluysa, en eski kaydın üzerine yazar.
    void list();			// Rehberdeki tüm kişileri listeler.
    void show(int);		// Belirli bir indeksteki kişinin detaylarını gösterir.
    int size();			// Rehberde kaç kişi olduğunu döndürür.
};
