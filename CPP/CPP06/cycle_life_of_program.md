
# Programın Yaşam Döngüsü
**Programın yaşam döngüsü, bir programın yazılmasından çalıştırılmasına kadar geçen süreçtir.**

## Süreçler
---

### Kaynak Kodun Yazılması
Kaynak kod, İnsan tarafından okunabilir kod dosyasıdır. C dilinde bu dosya genellikle .c uzantısıyla kaydedilir. Örneğin, main.c

### Ön İşlemci Aşaması (preprocessor)
Ön işleyici, yazılmış kaynak kodun derlenmeden önce işleyen bir programdır. Adını, kaynak kodu derleyiciye geçmeden önce işlediği için alır. Ön işleyicinin temel işlevi, kodun derleyiciye iletilmeden önce çeşitli işlemler yapmaktır.
- Ana Görevleri:
    1. Başlık Dosyalarının Dahil Edilmesi **`#include`**: Başlık dosyaları, başka kaynak dosyalarında tanımlanan fonksiyonlar, değişkenler ve diğer yapılarla ilgili bildirimler içerir. Ön işleyici, bu başlık dosyalarını kaynak koda dahil ederek, farklı dosyalar arasındaki bağı kurar.
    2. Makro Tanımlamaları **`#define`**: Ön işleyici, kod parçalarını daha kısa ve okunabilir hale getirmek için makro tanımlamaları kullanır. Makro, bir kod parçasına kısa bir ad atanmasını sağlar ve bu kısa ad, ön işleyici tarafından tam kodla genişletilir.
    3. Koşullu Derleme Komutları (`#ifdef, #ifndef, #endif`, `#else, #elif`): Ön işleyici, koşullu derlemeyi destekler. Bu, belirli koşullara bağlı olarak kodun belirli bölümlerinin derlenip derlenmeyeceğini kontrol eder.
**Özetle**, Ön işleyici kaynak kodun derleyiciye geçmeden önce çeşitli işlemler yapar. Başlık dosyalarını dahil eder, makroları genişletir ve koşullu derlemeyi kontrol eder. Bu işlemlerle kodun doğru ve verimli bir şekilde derleyiciye aktarılmasını sağlar. Yani, ön işleyici sadece kodu işleyip hazırlamaktan sorumludur; kodun doğruluğunu kontrol etmez.

### Derleme Zamanı (Compiling Time)
Derleme zamanı, bir programın kaynak kodunun makine diline çevrildiği aşamadır. Bu süreç, kaynak kodun derleyici tarafından işlenmesi ve çıktının, yani çalıştırılabilir bir programın oluşturulması için gerekli olan adımları içerir. Derleme aşamasında, ön işleyici tarafından hazırlanan kaynak kodu, derleyici tarafından makine diline (veya daha yaygın olarak, bir ara dil olan assembler diline) çevrilir. Bu aşama, kaynak kodunun daha anlaşılabilir bir biçime dönüştürülmesini sağlar. Derleyici, kaynak kodu satır satır kontrol eder ve her bir satırı derler.
- Derleme Zamanı Hataları 
    * Sözdizimi Hataları: Programın kurallara uymayan yazım hatalarıdır. Derleyici, bu tür hataları tespit ederek bir hata mesajı üretir.
    * Bağlantı Hataları: Bağlantı sırasında, eksik kütüphaneler veya yanlış bağlantılar nedeniyle oluşur. Linker, bu tür hataları bildirir.

### Bağlama (Linking)
Bağlama (Linking), derleme sürecinin son aşamasıdır ve bir programın çalıştırılabilir hale gelmesi için gerekli olan tüm parçaların (object dosyalarının) birleştirilmesi işlemini ifade eder. Bu aşamada, derleyici tarafından üretilen derlenmiş kodlar (object dosayalar) ve gerekli dış kütüphaneler, bir araya getirilerek tek bir çalıştırılabilir dosya oluşturulur. Bağlama işlemi, kodun tüm bileşenlerinin birleştirilmesi ve doğru şekilde adreslenmesini sağlar. Bağlama, genellikle iki ana türde yapılır: statik bağlama ve dinamik bağlama.
- Statik Bağlama (Static Linking)
    - Statik bağlama, derleme sırasında tüm gerekli kütüphanelerin ve modüllerin, çalıştırılabilir dosyaya dahil edilmesi işlemidir. Bu sayede programın çalıştırılabilir dosyası tek başına tüm bağımlılıkları içerir.
- Dinamik Bağlama (Dynamic Linking)
    - Dinamik bağlama, çalıştırılabilir dosyanın yalnızca program çalıştırılmadan önce gerekli olan kütüphanelere işaret etmesini sağlar. Yani, programın dış kütüphaneleri çalışma zamanında (runtime) yüklenir.

### Çalıştırma Zamanı (Run Time)
Çalıştırma Zamanı (Run Time), Derleme ve bağlama aşamalarının ardından başlar ve programın gerçek işlevlerini yerine getirmeye başladığı zamandır. Bu aşamda programın bellek yönetimi, giriş/çıkış işlemleri, işlemci kullanımı ve diğer kaynaklar gibi dinamik işlemler devreye girer.
- Çalıştırma Zamanı Hataları
    - Bölgesel Hatalar (Segmentation Fault): Programın, izin verilmeyen bellek alanlarına erişmeye çalışması sonucu ortaya çıkar. Bu hatalar genellikle yanlış pointer kullanımı veya dizilerle ilgili hatalardan kaynaklanır.
    - Sonsuz Döngüler: Programın bir koşul altında, durması gereken bir döngüyü sonlandırmaması sonucu sürekli çalışması. Bu tür hatalar genellikle döngü koşullarının yanlış yazılmasından kaynaklanır.
    - Bölme Hatası (Division by Zero): Bir sayı sıfıra bölünmeye çalışıldığında oluşan hata.
    - Bellek Sızıntıları (Memory Leaks): Dinamik bellek tahsisi yapıldığında, tahsis edilen belleğin serbest bırakılmaması sonucu meydana gelir. Bu, programın uzun süre çalışması halinde bellek kaynaklarının tükenmesine yol açabilir.

**Özetle**, Programın yaşam döngüsü, bir programın yazılmasından çalıştırılmasına kadar geçen süreçtir. İlk aşama, kaynak kodun yazılmasıdır; bu kod, programcı tarafından yazılır ve genellikle `.c` gibi uzantılarla kaydedilir. Ardından, `ön işleyici` geçilir. Bu aşamada, başlık dosyaları eklenir, makrolar tanımlanır ve koşullu derleme yapılır. Bu işlemlerle kod, derleyiciye uygun hale getirilir. `Derleme zamanı`, kaynak kodun makine diline çevrildiği süreçtir. Bu aşamada, derleyici kodu analiz eder ve makine diline dönüştürür. Ancak, bu aşamada sözdizimi ve bağlantı hataları gibi hatalar da ortaya çıkabilir. `Bağlama (linking)` aşamasında, derlenmiş kodlar ve dış kütüphaneler birleştirilerek çalıştırılabilir dosya oluşturulur. Bu işlem statik veya dinamik bağlama şeklinde olabilir. Son olarak, `çalıştırma zamanı` başlar. Program artık gerçek işlevlerini yerine getirir ve dinamik işlemler devreye girer. Ancak, bu aşamada bölgesel hatalar, sonsuz döngüler, bölme hataları ve bellek sızıntıları gibi çalıştırma zamanı hataları meydana gelebilir. Bu hatalar, programın düzgün çalışmamasına veya bellek kaynaklarının tükenmesine yol açabilir.

[cycle-life](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)
