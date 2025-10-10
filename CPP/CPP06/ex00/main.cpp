

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        return (1); 
    ScalarConverter::convert(argv[1]);

    return 0;
}





/* ex00
Amaç, convert fonkskiynunda parametre olarak verilen string değerini 
4 farklı tipe (char, float(tek duyarlılık), double(çift duyarlılık), int) dönüştürüp ekrana yazdırmaktır.

Adımlar
1. İlk önce gelen argümanların hangi tipte olduğunu kontrol et (atoi, isdigit, stof)
2. Dönüşüm Fonksiyonları Yaz
3. Karakterin Yazdırılması
4. Pseudo-literals Kontrolü

---
Static_cast -> Temel Veri tipler arasında yapılan Güvenli bir tür dönüşümüdür.
Derleme Zamanında Kontrol edilir.

---
std::setprecision(1) -> virgülden sonra 1 basamak gösterir
std::fixed -> sayı bilimsel olarak gösterilmesin diye yapıyrouz ve ondalıklı olarak gösterililecektir.

---
Float ve Double farkı aslında Float bellekte 32 bit 
Double ise 64 bit yer kaplamasıdır.
*/
