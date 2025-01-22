
enum nedir ?
-----------
Enum, C'de kullanıcı tanımlı bir veri türüdür. 
Esas olarak tamsayı sabitlerine isim atamak için kullanılır, 
isimler bir programın okunmasını ve bakımını kolaylaştırır.
ve sabitleri gruplandırmak için kullanılır. 
C'deki enum'lar, tam sayı sabitlerine isim atamanıza izin vererek kodu daha okunabilir hale getirir.
Sabitlere numaralar atanır ve varsayılan olarak bu numaralar 0'dan başlar.

amaç:
	Sabit değerleri gruplayarak anlamlı isimler oluşturmak.
veri türü:
    Sadece tamsayı sabitleri içerir.
Değişkenler: 
    Sabit (readonly) değerler içerir.

struct ise
amaç:
    Birden fazla türdeki değişkeni bir arada saklamak.
veri türü:
    Farklı türde değişkenler içerebilir.
Değişkenler:
    Dinamik ve değiştirilebilir değerler içerir.


C dilinde Enumeration (Enum), kullanıcı tarafından tanımlanan özel bir veri türüdür. Bu tür, kullanıcı tarafından adlandırılmış sabit tam sayılardan (integer) oluşur. Enum kullanmak, tam sayı değerlerini isimlendirmek suretiyle programın öğrenilmesini, anlaşılmasını ve bakımını kolaylaştırır. Bu sayede aynı ya da farklı bir programcı tarafından daha anlaşılır ve bakımı kolay kodlar yazılabilir.


fonksiyon işaretçiler
---------------------
bir fonksiyonun adresini tutan ve bu adres aracılığıyla o fonksiyonu çağırmanıza olanak tanıyan işaretçilerdir. Fonksiyon tanımlarında başında kullanılan *, fonksiyon işaretçisini belirtir. Bu işaretçi, bir fonksiyonun adresini tutar. 


Neden stackleri linked list ile tanımladık
------------------------------------------
Stack'leri linked list ile tanımlamanın amacı, dinamik ve esnek bir yapı sağlamaktır. Bellek, yalnızca ihtiyaç duyulan elemanlar için tahsis edilir ve bu sayede sabit boyut sınırlaması ortadan kalkar. Push ve pop işlemleri, yalnızca pointer'ları güncelleyerek hızlıca gerçekleştirilir. Linked list, boyutun önceden bilinmediği veya sık sık değiştiği durumlarda idealdir. Ayrıca, dizilerde karşılaşılan kapasite sorunlarını ortadan kaldırarak bellek kullanımını optimize eder.


Ctrl + D
--------
CTRL + D terminalde EOF (End Of File) karakterini gönderir.
Ctrl+D, bir Veri İletimi Sonu (EOT) sinyali gönderir ve bu genellikle giriş okuyan bir programın giriş dosyasını kapatmasına neden olur. ASCII tablosundaki konumu, Dosya Sonu (EOF) kontrol karakteriyle ilişkilidir.




total / 2 + total % 2 
-----------------------
Bu ifade, toplam eleman sayısını ikiye böldüğümüzde ortaya çıkabilecek 
**tek sayı** durumlarını doğru bir şekilde yönetmek için kullanılır.
total / 2: Toplam eleman sayısını ikiye böler ve tam sayıya yuvarlanmış şekilde bölme sonucu verir.
total % 2: toplam eleman sayısının tek mi yoksa çift mi olduğunu kontrol eder. eğer 0 ise çift 1 ise tek
Bu ifade, elemanların eşit veya dengeli bir şekilde bölünmesini garanti etmek için kullanılır ve özellikle tek sayıda eleman olduğunda doğru bir şekilde çalışır.


Quick sort algoritmasını çalışma mantığı
----------------------------------------
1. Pivot Seçimi:
Yığındaki elemanları iki gruba ayırmak için medyan (pivot) hesaplanır.

2. Elemanları Gruplara Ayırma:
Pivot değerine göre elemanlar ayrılır:
    - quick_sort_a: Küçük olanlar stack_b'ye.
    - quick_sort_b: Büyük olanlar stack_a'ya.

3. Döndürme İşlemleri:
Ayrılma sırasında kaybolan sıralamayı düzeltmek için ROTATE ve REVERSE_ROTATE işlemleri yapılır.

4. Rekürsif Bölme:
Her grubu daha küçük parçalara ayırmak için fonksiyon kendini çağırır.
quick_sort_a ve quick_sort_b sıralama işlemini ayrı ayrı yapar.

5. Durdurma Koşulları:
Yığın uzunluğu 1 veya daha küçükse ya da zaten sıralıysa işlem durur.







/*
Tekrar edilecek konular
-----------------------
-Fonksiyon işaretçileri
-"Makefile (program run ve compile time) ve ileri seviye"
-"Compiler" "Flags" ve "Optimizasyon" (-Wall, -Werror, -O2, -g, gdb, valgrind...)
-"Header Dosyalar ("makro", "enum" "struct", "Include guard", "extern", "inline", "Preprocessor")
-Quick Sort ve Stack
-Time Complexity, Space Complexity, Big-O Notation
-Pointer, Pointer to Pointer, Adres Referansı
-Dinamik Bellek tahsisi (malloc, free, ..) ve bunlar hangi bellek alanında tahsis ediliyor
-Bazı bash komutları:
-shuf -i 1-1000 -n 10, find . -type f -name "*.c", tree, history, whereis,
-Bellek Düzeni (memory layout)
-ANSI kodu 
*/


ARG=($(shuf -i 1-2000000 -n 100)); ./push_swap $ARG | wc -l
ARG=($(seq -200000  200000 | shuf -n 100 | tr '\n' ' ')); ./push_swap $ARG | wc -l

fish:
set ARG (seq -200000 200000 | shuf -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l


Memory Leak Nedir
-----------------
Memory Leak (Bellek Sızıntısı), bir programın dinamik bellek ayırırken, 
bu belleği düzgün şekilde serbest bırakmaması sonucu belleğin boşuna tüketilmesidir. 
Yani, bir program belleği ayırır ancak bu belleği serbest bırakmazsa, 
bu bellek sistemde kullanılmaz halde kalır ve zamanla belleği tüketir. 
Bu da sistemin performansını olumsuz etkileyebilir.
Memory Leak Tespiti: "Valgrind" ve "AddressSanitizer"



Segmentation Fault Hatasına yol açan hatalar
-----------------------------------------Ctrl + D
--------
CTRL + D terminalde EOF (End Of File) karakterini gönderir.
Ctrl+D, bir Veri İletimi Sonu (EOT) sinyali gönderir ve bu genellikle giriş okuyan bir programın giriş dosyasını kapatmasına neden olur. ASCII tablosundaki konumu, Dosya Sonu (EOF) kontrol karakteriyle ilişkilidir.

---
Segmentation Fault (Segfault) hatası, 
programın izin verilmeyen bir bellek alanına erişmeye çalışması nedeniyle oluşur. 

Segfault Türleri:
1. Dinamik olarak ayrılmayan bir bellek alanına erişmek: 
Bellek dinamik olarak ayrılmadan örneğin bir işaretçi kullanılarak erişim yapılmaya çalışıldığında oluşur.

2. Serbest bırakılmış bir alana erişmek: 
free() ile serbest bırakılmış bir bellek bloğuna tekrar erişmeye çalışmak.

3. Null (boş) bir işaretçiye erişmeye çalışmak: 
Bir işaretçi NULL veya nullptr olduğunda, ona erişim yapılmaya çalışıldığında segfault oluşur.

4. Özyinelemeli fonksiyon çağrılarında stack bellek sınırının aşılması:
Derin özyinelemeli (rekürsif) fonksiyon çağrıları nedeniyle stack belleği tükenebilir, 
bu da stack overflow'a yol açar.


Bus Error | Abort Error 
Buffer Overflow | Stack Overflow


zaman dalgası sorunları çözmek için
---
sudo date --set="2025-01-20 17:04:31"
