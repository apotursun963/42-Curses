
#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;      // str'nin adresini tutuan pointer
    std::string &stringREF = str;       // str'nin referansı (takma adı)

    // Adresler
    std::cout << "Memory address of str variable: " << &str << std::endl;         // str'nin bellekteki adresi
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;   // stringPTR'nin tuttuğu adres (str'nin adresi)
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;  // stringREF'in adresi (str'nin adresi ile aynı)

    // Değerler
    std::cout << "Value of str variable: " << str << std::endl;           // str'nin değeri
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;   // stringPTR'nin gösterdiği değeri yazdır
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;    // stringREF'in değeri (str ile aynı)

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

Pointer: Adres tutar, Başlangıç Değeri Olmayabilir, null olabilir.
Referans: Takma ad, Başlangıç Değeri olması gerekiyor, null olamaz.
Referans ve pointer kullandığımızda gerçek nesnenin bellek adresini veriyoruz, 
nesnenin kendisini değil.


- KOPYALAMA
void func(std::string str) {  // str kopyalanır
    str += " modified";
}

int main() {
    std::string original = "Hello World";
    func(original);  // original'in bir KOPYASI oluşturulur
    // original değişmez, kopya üzerinde işlem yapılır
}

- REFERANS
void func(std::string& str) {  // Referans, kopya YOK
    str += " modified";
}

int main() {
    std::string original = "Hello World";
    func(original);  // Sadece original'in adresi geçirilir
    // original değişir
}


*/
