
#include "RPN.hpp"

/*
1. argümanın sayı olup olmadığını kontrol edeceksin (+ - / * (hariç))
2. sayılar 10'nun üzerinde olmayacak (10 da olmayacak) (0-9)
*/

int main(int argc, char **argv) {
    if (argc == 2) {
        RPN rpn;
        rpn.ctrl_argument(argv[1]);
        rpn.calc_expression(argv[1]);
        return (0);
    }
    else
        std::cerr << "wrong argument number." << std::endl;
    return (1);
}



/*

ARGUMENTS:
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>

ex01: Reverse Polish Notation (RPN)
Reverse Polish Notation (Ters Lehçe Gösterimi) kullanarak verilen bir matematiksel ifadeyi hesaplayan bir C++ programı yazmak.

Mantığı:
Normal matematikte: 3 + 4
RPN'de: 3 4 +

- Operatörler (+ - * /) her zaman sonradan gelir
- Parantez yok
- Öncelik yok → sıra her şeyi belirler

Program tek bir string argüman alır:
- ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

Kurallar:
- Sayılar 0–9 arası tek hanelidir
- Aralar boşlukla ayrılır
- Parantez ❌
- Ondalık sayı ❌


Hesaplama mantığı nasıl yapılır
Stack Nasıl Kullanılır?
1. Boş bir stack oluştur
2. Soldan sağa token’ları oku
3. Eğer token sayıysa → stack’e push
4. Eğer token operatörse:
    . stack’ten iki sayı pop et
    . işlemi yap
    . sonucu tekrar stack’e push
5. İş bitince stack’te tek eleman kalmalı
6. Bu eleman → sonuç



❌ Hata Durumları

Aşağıdakilerden biri olursa:
    . Stack’te yeterli sayı yokken operatör gelirse
    . Tanımsız karakter ((, a, vs.)
    . Bölme sırasında / 0
    . Program sonunda stack’te 1’den fazla eleman varsa
👉 stderr’e:


ÖRNEK
-----
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

| Token | Yapılan İşlem | Stack   |
| ----- | ------------- | ------- |
| 8     | push          | [8]     |
| 9     | push          | [8, 9]  |
| *     | 8 * 9 = 72    | [72]    |
| 9     | push          | [72, 9] |
| -     | 72 - 9 = 63   | [63]    |
| 9     | push          | [63, 9] |
| -     | 63 - 9 = 54   | [54]    |
| 9     | push          | [54, 9] |
| -     | 54 - 9 = 45   | [45]    |
| 4     | push          | [45, 4] |
| -     | 45 - 4 = 41   | [41]    |
| 1     | push          | [41, 1] |
| +     | 41 + 1 = 42   | [42]    |



NEDEN STACK KULLANIYORSUN
RPN ifadeleri soldan sağa okunur ve her operatör kendinden önce gelen son iki sayıyla işlem yapar.
Stack, LIFO yapısı sayesinde bu iki sayıyı otomatik ve doğru sırayla verir.
Bu sayede öncelik, parantez veya geri dönme ihtiyacı olmadan ifade tek geçişte hesaplanır.
Bu yüzden RPN için en doğru ve doğal veri yapısı stack’tir.


RPN’de ifade soldan sağa okunur:
- Sayı görürsen → sakla
- Operatör görürsen → en son saklanan iki sayıyı al, işlem yap, sonucu geri koy
Yani sistem şunu ister:
- “Son giren, ilk çıkar” (LIFO)
*/