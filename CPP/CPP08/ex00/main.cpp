


#include "easyfind.hpp"



int main(int, char **)
{
    // std::vector<int> vec = {7, 235, 213, 75, 3};     +98 standardında süslü parantez yasak 

    std::vector<int> vec;
    vec.push_back(7);
    vec.push_back(235);
    vec.push_back(75);
    vec.push_back(5432);

    try {
        int res = easyfind(vec, 75);
        std::cout << "value founded -> " << res << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
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
Iterator’lar sayesinde:
- Container içindeki her elemana sırayla erişebilirsin,
- Elemanları okuyabilir, değiştirebilir, silebilir veya ekleyebilirsin,
- Container’lar arasında ortak bir dolaşım yöntemi kullanabilirsin.

*/