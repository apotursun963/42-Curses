
# Container
container (kap) kavramı, veri yapılarının temelini oluşturur.
Bir container, C++’ta çok sayıda veriyi depolamak, yönetmek ve onlara erişmek için kullanılan bir sınıftır.
Yani, bir “veri kutusu” gibidir.

## Container Türleri
C++’ta container’lar, Standard Template Library (STL) içinde bulunur ve üç ana kategoriye ayrılır.

### 1. Sequence Containers (Sıralı Kaplar)
Öğeleri sıralı bir düzende, yani eklenme sırasına göre depolarlar.

1. `vector`: Dinamik boyutlu bir dizi (array) sağlayan bir STL (Standard Template Library) konteyneridir.
Normal diziler (int arr[5];) sabit boyutludur (static/sabit bellek ayırma), yani sonradan eleman eklenemez veya çıkarılamaz. vector ise boyutunu dinamik olarak artırıp azaltabilir. yani program çalışırken eleman ekleyip çıkarabilirsin. (Kısacası, Normal dizi sabit, vector ise esnektir.)
- Elemanları bellekte ardışık (contiguous) şekilde tutar (tıpkı normal dizi gibi).
- Dinamik olarak büyüyebilir veya küçülebilir.
- push_back() ile sona eleman eklenir.
- pop_back() ile sondan eleman silinir.
- insert() ile istediğimiz yere eleman eklenir.
- [] veya at() ile elemanlara erişilir.
- Türü şablon (template) olarak belirlenir → std::vector<int> veya std::vector<std::string> gibi.

2. `list`: std::list, C++’ta çift yönlü bağlı liste (doubly linked list) yapısını sağlayan bir STL konteyneridir.
std::list, elemanlarını bellekte ardışık değil, bağlantılı düğümler (nodes) şeklinde saklar.
Her düğüm (node): - Bir veri (data) - Önceki elemana (prev) ve sonraki elemana (next) gösterici içerir.
- push_back() ile sona eleman eklenir.
- push_front() ile başa eleman eklenir.
- advance() ile listedeki belirli iteratordeki konuma gidilir.
- Araya eleman eklemek veya silmek çok hızlıdır.
- Rastgele erişim yok → list[2] kullanamazsın.
- begin() ve end() kullanarak listede iterate dolaşabilirim
- veri tipi -> Şablon (template): `std::list<int>`, `std::list<std::string>`

3. `deque` (Double-Ended Queue (Çift Uçlu Kuyruk)): Hem başa hem de sona hızlı şekilde eleman ekleyip çıkarabilirsin. vector gibi rastgele erişim (random access) destekler: d[i] yazabilirsin. 
Özetle, vector + list karışımı gibi düşünebilirsin.
- push_front() başa eleman ekleme
- push_back() sona eleman ekleme
- pop_front() baştan silme
- pop_back() sondan silme
- Bellek düzeni, Dinamiktir blok blok bellek kullanır.
- veri tipi -> Şablon (template): `std::deque<int>`, `std::deque<std::string>`

4. `deque`: C++11 ile STL’ye eklenmiştir.
5. `forward_list`: C++11 ile STL’ye eklenmiştir. (Tek yönlü bağlı listedir)



### 2. Associative Containers (Eşleme Kapları)
### 3. Unordered Containers (Sırasız Kaplar)

![s](https://www.edureka.co/blog/wp-content/uploads/2019/08/3-1-1.jpg)

# ANSI Kodları
ANSI escape kodları, terminalde metin rengini, arka plan rengini ve stilini değiştirmeye yarar.
- \033[<style>;<text_color>;<background_color>m
    - \033 → Escape karakteri
    - <style> → metin stili (normal, kalın, altı çizili)
    - <text_color> → metin rengi
    - <background_color> → arka plan rengi
    - Sonlandırmak için: \033[0m

