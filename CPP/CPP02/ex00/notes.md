
Proje Açıklaması
---
Bu projede, "fixed-point" sayı tipini temsil eden bir sınıf tasarlayacaksın. Fixed-point sayılar, bilgisayarda tam sayı (int) ve kayan noktalı sayıların (float/double) bazı dezavantajlarını ortadan kaldırmak ve özellikle performans, doğruluk, aralık ve hassasiyet arasında daha iyi bir denge sunmak için tercih edilir. Grafik ve ses işleme gibi alanlarda sıkça kullanılırlar.
Yani, Kısacası C++ yerleşik olarak bulunmayan bir sayı veri tipini oluşturmak.
Fixed point, Sayının bir kısmı tam sayı, bir kısmı ise sabit bir sayıda "kesirli bit" olarak saklanır.
Kayan noktalı sayılar hassas fakat doğrulukları düşüktür, tam sayılar ise çok doğrudur fakat hassasiyetleri düşüktür Ve Fixed-point aritmetik, ikisinin arasında bir çözüm sunar.
Özetle, Fixed Point veri tipini temsil eden bir sınıf yazacak ve OCF kurallarına uyumamız gerekiyor.

---
Önemli
Sola kaydırmak (<< 8), sayının tüm bitlerini 8 pozisyon sola taşır.
Sağdan 8 tane sıfır eklenir

Sabit noktalı formatta, tam sayı kısmını saklarken ondalık için yer açmak gerekir.
8 bit sola kaydırınca, sayı 256 ile çarpılmış olur.
Böylece, ondalık kısmı için 8 bit boşluk bırakmış oluruz.

8 bit sola kaydırmamızın sebebi, sabit noktalı formatta sayının kesirli kısmı için bellekte yer açmaktır.
Yani, 8 bit sola kaydırınca, sayının en sağındaki 8 bit “boş” olur ve bu alanı kesirli kısmı saklamak için kullanırız.

Ne Oluyor?
- Sola kaydırınca: Sayının değeri 256 ile çarpılır (örneğin 5 → 1280).
- Sağdaki 8 bit: Artık kesirli kısmı saklamak için ayrılmıştır.
Yani, tam sayı kısmı solda, kesirli kısmı sağda tutulur.
Örnek:
- 5.75’i fixed-point’e çevirmek için:
5.75 × 256 = 1472       << 8
- 1472’nin binary hali: 00000000 0000000 00000101 11000000
    - Soldaki bitler tam kısmı (5), sağdaki 8 bit kesirli kısmı (.75) temsil eder.
Kısaca:
- Sola kaydırınca: Tam sayı kısmı büyür, sağda kesirli kısım için yer açılır.
- O boş kalan 8 bit: Kesirli kısmı saklamak için kullanılır.
Böylece hem tam hem kesirli kısmı tek bir integer’da tutabilirsin.

Projede kesirli kısmı doğrudan elde etmen gerekmiyor; çünkü fixed-point formatında, tam ve kesirli kısım zaten tek bir integer’da saklanıyor.
Senin yapman gereken, fixed-point değeri saklamak ve istenirse gerçek değeri (float veya int olarak) geri döndürmek.

int ve float tipindeki sayıları fixed-point'e çevirmek için 8 bit sola kaydırma (çarpma) mantığı kullanılır.
Ancak, float tipini fixed-point'e çevirirken önce 256 ile çarpıp sonra yuvarlaman gerekir.

- Integer'ı Fixed-point'e Çevirme
int value = 100;
int fractionalBits = 8;
int fixedPointValue = value << fractionalBits; // 100 << 8 = 25600
<< operatörü, integer'ı 8 bit sola kaydırır. Bu, 100'ü 256 ile çarpmakla aynıdır.

- Fixed-point'ten Integer'a Geri Çevirme
int restoredValue = fixedPointValue >> fractionalBits; // 25600 >> 8 = 100


- Float → Fixed-point
float f = 5.75f;
int fractionalBits = 8;
int fixedValue = static_cast<int>(roundf(f * (1 << fractionalBits))); // 5.75 * 256 = 1472

- Fixed-point → Float
float restored = static_cast<float>(fixedValue) / (1 << fractionalBits); // 1472 / 256 = 5.75
Fixed-point değeri tekrar 256'ya bölünür.


Kısacası, Fixed Point sayısı, Tam ve kesirli kısım tek integer’da saklanıyor
---


Örnek
Temel Prensip
Fixed-point sayı, bir tam sayı (integer) olarak saklanır; bu tam sayı, gerçek değeri elde etmek için sabit bir bölene (2^n, n = kesirli bit sayısı) bölünür.
- 8 Kesirli Bit (Fractional Bits)
Varsayalım ki 8 kesirli bit var (n = 8).
Saklanan değer: int_value
Gerçek değer: real_value = int_value / 256
- Neden 256?
Çünkü 8 kesirli bit = 2^8 = 256.
10 kesirli bit olsaydı, bölünen 1024 olurdu.
- Tam sayıdan fixed-point'e
Saklamak istediğin değer: 5.75
int_value = 5.75 × 256 = 1472
Yani, bellekte 1472 olarak saklanır.

Fixed-point sayılar, bellekte integer olarak tutulduğu için toplama/çıkartma işlemleri direkt integer gibi yapılır.
Örneğin:
    - 1.5 + 2.25
    - int_value1 = 1.5 × 256 = 384
    - int_value2 = 2.25 × 256 = 576
    - Toplam = 384 + 576 = 960
    - Gerçek değer = 960 / 256 = 3.75

- Tam kısım: Noktadan önceki bölüm (örneğin, 5.75 → 5)
- Kesirli kısım: Noktadan sonraki bölüm (örneğin, 5.75 → 0.75)

Yani Kısacası, Fixed Point
- Bir tam sayı olarak saklanır.
- Kesirli kısmı, sabit bir bölene bölerek elde edilir.
- Toplama/çıkarma aynı, çarpma/bölme sonrası tekrar bölme/çarpma gerekir.


OCF
---
From Module 02 to Module 09, your classes must be designed in the Orthodox
Canonical Form, except when explicitly stated otherwise.

"Orthodox Canonical Form" (OCF) ya da Kanonik Biçim, C++ dilinde sınıfların kaynak (resource) yönetimi ile ilgili bir kavramdır. 
Bu form, bir sınıfın kendi kaynaklarını (heap bellekteki veriler gibi) doğru şekilde yönetebilmesi 
için gerekli olan özel üye fonksiyonları tanımlamasını ifade eder.

C++’ta bir sınıf kendi belleğini yönetiyorsa (örneğin new veya malloc kullanıyorsa), 
bu belleğin kopyalanması, taşınması ve yok edilmesi gibi işlemlerin doğru çalışabilmesi 
için bazı özel fonksiyonları tanımlaması gerekir.

OCF, aşağıdaki 4 özel fonksiyonun tanımlanması anlamına gelir:
1. Default Constructor (kurucu fonksiyon)
2. Copy Constructor (Başka bir nesneden kopyalama yaparak yeni nesne oluşturan fonksiyon)
3. Copy Assignment Operator (Copy Assignment Operator)
4. Destructor (Nesne yok edilirken çağrılan, belleği temizleyen fonksiyon)

Yani: kurucu, kopya kurucu, kopya atama operatörü ve yıkıcı **eksiksiz** olmalı.


---

