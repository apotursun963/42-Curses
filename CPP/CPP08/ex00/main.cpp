
#include "easyfind.hpp"

int main(int, char **)  // farklı container yapılarını daha ekle
{
    {
        std::cout << "<<<List Test>>>" << std::endl;

        std::list<int>lst;
        lst.push_back(34);
        lst.push_back(25);
        lst.push_back(734);

        try {
            std::list<int>::iterator res1 = easyfind(lst, 25);
            std::cout << "value founded -> " << *res1 << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "<<<Vector Test>>>" << std::endl;
        
        std::vector<int> vec;
        vec.push_back(7);
        vec.push_back(235);
        vec.push_back(75);
        vec.push_back(5432);
    
        try {
            std::vector<int>::iterator res2 = easyfind(vec, 33);
            std::cout << "value founded -> " << *res2 << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}




/* ex00
Görev -> Bir container (örneğin vector<int>, list<int> gibi) içinde belirli bir integer değeri aramak.

easyfind func;
“easyfind adında bir fonksiyon şablonu (template) yaz.
Bu fonksiyon, birinci parametre olarak bir (tamsayı) container’ı, ikinci parametre olarak bir tamsayı değer alır.
Container içinde bu tamsayıyı bul ve ilk geçtiği yeri döndür.
Eğer bulunamazsa bir hata (örneğin exception) fırlat veya özel bir hata değeri döndür.”


Iterator
bir container’ın (örneğin vector, list, map) içindeki elemanlarda adım adım 
dolaşmanı sağlayan bir “gösterici” (pointer benzeri nesne)dir.
vector içindeki bir elemanın adresini tutar
Ama direkt elemanın kendisi değil, sadece o elemanın konumunu gösterir.
* operatörü iterator’ün işaret ettiği elemanı almak için kullanılır.
Iterator’lar sayesinde:
- Container içindeki her elemana sırayla erişebilirsin,
- Elemanları okuyabilir, değiştirebilir, silebilir veya ekleyebilirsin,
- Container’lar arasında ortak bir dolaşım yöntemi kullanabilirsin.

*/