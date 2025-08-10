
#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:    // neden bunları private yaptım çünkü "subjecte bizden sadece sınıf içinde kullanılacak değişkenler private olmalı diyordu."
    Contact contacts[8];
    void printField(std::string);
public:
    int count;				// Şu anda rehberde kaç kişi olduğunu tutar.
    int next;				// Yeni bir kişi ekleneceğinde hangi dizin kullanılacak onu gösterir (dairesel ekleme için kullanılır).
    
    void add(Contact&);	// Yeni bir kişi ekler. Eğer 8 kişilik yer doluysa, en eski kaydın üzerine yazar.
    void list();	// Rehberdeki tüm kişileri listeler.
    void show(int);		// Belirli bir indeksteki kişinin detaylarını gösterir.
};
