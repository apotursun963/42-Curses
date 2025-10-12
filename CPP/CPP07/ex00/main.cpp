
#include "whatever.hpp"

int main(void)
{
    int a = 7, b = 10, c = 7;
    swap(a, b);
    int res_min_int = ::min(a, b);
    int res_max_int = ::max(a, b);
    int res_eq_int = ::max(c, b);

    std::cout << "swap -> " << "a: " << a << ", b: " << b << std::endl;
    std::cout << "min -> " << res_min_int << std::endl;
    std::cout << "max -> " << res_max_int << std::endl;
    std::cout << "max -> " << res_eq_int << std::endl;

    std::cout << "-------\n";

    /*
    stringlerde Karşılaştırma mantığı ilk karakterden başlar → eşitse sonraki karakterlere bakar.
    */
    std::string str1 = "abdullah", str2 = "tursun", str3 = "abdullah";
    swap(str1, str2);
    std::string res_min_str = ::min(str1, str2);
    std::string res_max_str = ::max(str1, str2);
    std::string res_eq_str = ::max(str2, str3);
    
    std::cout << "swap -> " << "str1: " << str1 << ", str2: " << str2 << std::endl;
    std::cout << "min -> " << res_min_str << std::endl;
    std::cout << "max -> " << res_max_str << std::endl;
    std::cout << "max -> " << res_eq_str << std::endl;
    
    return 0;
}



/* ex00
üç fonksiyon yazılacak
- swap: parametre olarak verilen iki değeri swap(takas) edecek. return yok
- min: parametre olarak verilen iki değeri karşılaştırır. küçük olan return edilir. eğer ikisi eşitse ikinci return edilir
- max: parametre olarak verilen iki değeri karşılaştırır. Büyük olan return edilir. eğer ikisi eşitse ikinci return edilir
Bu üç fonksiyon her hangi bir tip ile çalışabilmeli istenilen tek şey her iki parametre aynı tipte olacak
ve bütün karşıaştırma operatörlerini desteklemeli
*/


