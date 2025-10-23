
#include "Span.hpp"

int main(int, char **)
{
    Span sp(5);

    try {
        sp.addNumber(74);
        sp.addNumber(4);
        sp.addNumber(50);
        sp.addNumber(2);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int shn = sp.shortestSpan();
        std::cout << "Shortest span value is: " << shn << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int lng = sp.longestSpan();
        std::cout << "Longest span value is: " << lng << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


/* ex01
Span Sınıfı maxmimum N tane sayı saklayabilmesi gerekiyor.
N, sınıfın constructor’ına parametre olarak geçilen unsigned int bir sayı olacak.
    - Span sp = Span(5); // 5 sayı saklayabilir
Eğer addNumber() ile N’den fazla sayı eklemeye çalışırsan, exception fırlatmalı.
addNumber() Bu fonksiyon, Span’a tek bir sayı ekler.
    - addNumber(6) -> 6 sayısı eklendi
Eğer sınıf zaten N sayı saklıyorsa, ekleme yapmaya çalıştığında hata fırlatmalı.

shortestSpan() → İçindeki sayılar arasındaki en küçük farkı bulur.
longestSpan() → İçindeki sayılar arasındaki en büyük farkı bulur.
Eğer sayılar 0 veya 1 tane ise, span bulunamaz → exception fırlat.

En az 10,000 sayı ile test etmen öneriliyor. Daha fazlası daha iyi.

iterator ile toplu ekleme
addNumber()’u binlerce kez çağırmak yerine birden fazla sayıyı tek seferde ekleyebilmek için iterator kullan.
*/
