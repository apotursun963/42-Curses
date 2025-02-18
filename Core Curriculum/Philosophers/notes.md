# Philosophers

Bu projede, her filozof bir iş parçacığı (thread) olarak oluşturulacak ve 
her bir filozofun kullanacağı çatallar, mutex ile korunacaktır. 
Bu sayede her filozof yalnızca bir çatala aynı anda erişebilir.

Problemde, bir grup felsefeci yemek yemek için çatallar (forks) paylaşmak zorundadır. 
Aynı anda yalnızca bir çatalı tutabilirler ve her felsefeci, yemek yemek için iki çatala ihtiyacı vardır.


## Kurallar
--------
- Bir yuvarlak masa etrafında oturan filozoflar var.
- Ortada büyük bir spagetti tabağı bulunuyor.
- Filozoflar 3 farklı durumdadır: Düşünme, yeme, uyuma.
- Filozoflar yemek yiyebilmek için iki çatal almak zorundadır.
- Masanın üzerinde, filozof sayısı kadar çatal bulunmaktadır.
- Bir filozof, ancak hem sağındaki hem solundaki çatalı aldığında yemek yiyebilir.
- Bir filozof yemek yedikten sonra çatalını bırakıp uyur ve sonra tekrar düşünmeye başlar.
- Bir filozof, belirlenen süre boyunca yemek yiyemezse açlıktan ölür ve simülasyon sona erer.

Proje Adımları
1. Thread ve Mutex kavramlarını güzel bir şekilde öğren ve egzersizler yap
2. Philosopher projesinin ne olduğunu öğren / problemi iyice kavra (Dining Problem)
