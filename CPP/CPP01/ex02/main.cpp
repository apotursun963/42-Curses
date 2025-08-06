
#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;      // str'nin adresini tutuan pointer
    std::string &stringREF = str;       // str'nin referansı (takma adı)

    // Adresler
    std::cout << &str << std::endl;         // str'nin bellekteki adresi
    std::cout << stringPTR << std::endl;   // stringPTR'nin tuttuğu adres (str'nin adresi)
    std::cout << &stringREF << std::endl;  // stringREF'in adresi (str'nin adresi ile aynı)

    // Değerler
    std::cout << str << std::endl;           // str'nin değeri
    std::cout << *stringPTR << std::endl;   // stringPTR'nin gösterdiği değeri yazdır
    std::cout << stringREF << std::endl;    // stringREF'in değeri (str ile aynı)

    return 0;
}


/*
Pointer (İşaretçi)
Bir değişkenin bellekteki adresini tutar.
Yani, bir pointer başka bir değişkenin nerede saklandığını bilir ve o adrese erişebilir. 
Değerini değiştirebilir, farklı adresleri gösterebilir.
Null (boş) olabilir.
Gösterdiği değere * ile erişilir, adresine & ile erişilir.

Referans
Referans, bir değişkenin başka bir isimle (takma adla) kullanılmasını sağlar.
Bir referans tanımlandığında, hep aynı değişkeni gösterir ve doğrudan o değişken gibi davranır. 
Null olamaz, mutlaka bir değişkene bağlıdır. C++’da & işaretiyle tanımlanır.

Pointer: Adres tutar, değiştirilebilir, null olabilir.
Referans: Takma ad, değiştirilemez, null olamaz.
*/