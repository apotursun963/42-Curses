
# STL (Standard Template Library) Nedir ?

STL, C++ standart kütüphanesi içinde yer alan;
- veri yapıları (container)
- algoritmalar
- iterator’lar
- fonksiyon nesneleri (functor)
gibi bileşenlerden oluşan şablon (template) tabanlı bir kütüphanedir.

apo sen STL çok iyi bir şekilde öğren ve güzel bir markdown dosyası oluştur ve UNUTMA

-------


# STL (C++ Standard Template Library) — Aptala Anlatır Gibi, Ama DETAYLI

**Hedef:** C++’ın STL’ini (Standard Template Library) en temelden başlayıp, gerçek hayatta işe yarayan detaylara kadar **adım adım, örneklerle** anlatmak. "Neden, ne zaman, nasıl" sorularını netleştirip seni gerçek kod yazarken hata yapmaktan korumak.

---

## İçindekiler

1. [STL nedir, neden var?](#1-stl-nedir-neden-var)
2. [Temel kavram: Container — Iterator — Algorithm üçlüsü](#2-temel-kavram-container—iterator—algorithm-üçlüsü)
3. [Konteyner türleri — detaylı anlatım (üye fonksiyonlar, complexity, invalidation)](#3-konteyner-türüleri)

   * Sequence containers — detaylı
   * Associative containers — detaylı
   * Unordered associative — detaylı
   * Container adapters — detaylı
4. [İteratörler — kategoriler, gereksinimler, örnekler](#4-iteratörler)
5. [STL Algoritmaları — kategori kategori derinlemesine](#5-algoritmalar)

   * Non-modifying
   * Modifying
   * Sorting & ordering
   * Set algorithms
   * Heap algorithms
   * Numeric
   * Partition / Permutations / Misc
   * Parallel variants & ranges notes
6. [Functors / Lambdas / std::function / Comparator — derinlemesine](#6-functors-lambdas-stdfunction-comparator)
7. [Emplace vs push, move semantics, perfect forwarding — detaylar + örnekler](#7-emplace-move-forward)
8. [Node handles, hints, rehash/allocator notları (ileri)](#8-node-hints-rehash)
9. [Pratik örnekler — gerçekçi, satır satır açıklama](#9-pratik-örnekler)
10. [Cheat sheets: hızlı referans tablolar (membership, complexity, invalidation)](#10-cheatsheets)
11. [Sık yapılan hatalar ve nasıl düzeltilirler (pattern’ler)](#11-pitfalls)
12. [İleri seviye ve alıştırmalar](#12-ileri)

---

## 1) STL nedir, neden var?

Kısaca: STL bir dizi **genel (template)** veri yapısı ve algoritmadan oluşur. Amaç: tekrar yazmayı azaltmak, portatif, test edilmiş ve performans garantili araçlar vermek.

STL öğeleri - kısaca:

* **Containers**: veriyi saklayan tipler (std::vector, std::map...).
* **Algorithms**: kapsayıcıdan bağımsız işlemler (std::sort, std::copy...).
* **Iterators**: algoritmalar ile konteynerler arasında köprü — pointer benzeri soyutlama.
* **Utilities**: pair, tuple, functional, numeric gibi yardımcı yapılar.

Neden öğrenmelisin: çünkü hatalı veri yapısı seçimi veya iterator invalidation performans/kod hatalarına doğurur. STL doğru kullanıldığında hem hızlı hem güvenilir sonuç verir.

---

## 2) Temel kavram: Container — Iterator — Algorithm üçlüsü

Algoritma örneği: `std::sort(v.begin(), v.end())` — algoritma konteynerin içini bilmez; sadece iterator’lerin `++`, `*`, `-` gibi yeteneklerine güvenir. Bu yüzden iterator kategorileri önemlidir (bazı algoritmalar random-access iterator ister).

---

## 3) Konteyner türleri — detaylı anlatım (üye fonksiyonlar, complexity, invalidation)

Aşağıda her bir konteyner için: 1) tanım 2) önemli üye fonksiyonlar (prototype stili), 3) karmaşıklık garantileri 4) iterator/reference invalidation kuralları 5) tipik kullanım ve ipuçları 6) küçük örnek.

### A) std::vector<T>

**Tanım:** Contiguous (ardışık) dinamik dizi.

**Sık kullanılan üye fonksiyonlar (prototip, özet):**

```cpp
explicit vector();
vector(size_type n, const T& val = T());
template<class InputIt> vector(InputIt first, InputIt last);
vector(const vector&);
vector(vector&&) noexcept;
vector& operator=(const vector&);
vector& operator=(vector&&) noexcept;
~vector();

void push_back(const T&);
void push_back(T&&);
template<class... Args> void emplace_back(Args&&... args);
iterator insert(const_iterator pos, const T&);
iterator insert(const_iterator pos, T&&);
iterator erase(const_iterator pos);
iterator erase(const_iterator first, const_iterator last);
void reserve(size_type new_cap);
void resize(size_type count);
size_type size() const noexcept;
size_type capacity() const noexcept;
T& operator[](size_type pos);
T* data() noexcept;
```

**Zaman karmaşıklıkları (genel):**

* `operator[]`, `at`, `front`, `back`: O(1)
* `push_back`: amortize O(1); reallocation sırasında O(n)
* `insert`/`erase` ortada: O(n)
* `reserve`: amortize yeniden tahsis sayısını azaltır

**Iterator / reference invalidation:**

* `push_back` ve `emplace_back`: *eğer* kapasite yeterliyse mevcut iteratorler korunur; *kapasite artışıyla* reallocation olursa **tüm iteratorler, pointerlar ve referanslar** geçersizleşir.
* `insert`/`erase`: etkilenen konum sonrası iteratorler ve referanslar geçersizleşir (implementasyona göre detaya bak ama genelde soldan/sağdan etkilenir).

**Kullanım ipuçları:**

* `reserve(n)` ile büyüme maliyetini düşür.
* `emplace_back` ile gereksiz kopya/taşımadan kaçın.
* Eğer sabit aralıkta sıkça insert/erase yapıyorsan vector uygun değildir.

**Örnek:** top-k veya big-data için dynamic array.

```cpp
std::vector<std::string> names;
names.reserve(1000);
names.emplace_back("Alice");
```

---

### B) std::deque<T>

**Tanım:** Çift uçlu queue. Bellek tek blok olmayabilir; bloklar halinde olur.

**Temel fonksiyonlar:** (vector’e benzer; ek olarak push_front/emplace_front/pop_front)

```cpp
push_front, emplace_front, pop_front, push_back, emplace_back, pop_back;
operator[], at, front, back;
insert, erase, clear;
```

**Karmaşıklık:**

* `push_front`, `push_back`: amortize O(1)
* `operator[]`: O(1) (ancak vector ile kıyasla hafifçe daha yavaş)
* `insert` ortada O(n)

**Invalidation:**

* `push_front`/`push_back` bazen bazı iteratörleri geçersiz kılabilir. Reallocation/rehashing benzeri değil ama blok yönetimi yüzünden garantiler vector’dan farklıdır — kritik kodda dokümantasyona bak.

**Kullanım:** Baş/son ekleme/silme gerektiğinde; queue/stack davranışı ama başa da hızlı ekleme gerekiyorsa.

---

### C) std::list<T> (doubly-linked list)

**Tanım:** Her öğe ayrı node; iki yönlü bağ.

**Önemli fonksiyonlar (seçme):**

```cpp
push_back, push_front, emplace_back, emplace_front;
insert(iterator pos, const T& val);
erase(iterator pos);
splice(iterator pos, list& other); // node seviyesinde O(1) taşıma
remove(value), remove_if(pred);
unique(), merge(other), sort(), reverse();
```

**Karmaşıklık:**

* Insert/erase (iterator biliniyorsa): O(1)
* Size (implementation dependent historically, C++11 sonrası O(1) yaygın)
* Random access: O(n) (operator[] yok)

**İteratör invalidation:**

* Başka bir node eklenip/çıkarıldığında **diğer** iteratorler genelde korunur. Sadece silinen node’un iterator’ü bozulur.

**Güçlü yönü:** `splice` ile bir listeden diğerine node taşımak O(1) — bu, performans açısından unique.

**Kullanım:** Gerçekten ortadan O(1) insert/erase ve node taşımaya ihtiyaç varsa. Çoğu durumda vector daha hızlı (daha iyi locality) olur.

**Örnek:** görevin sıralarının node-level taşınması.

---

### D) std::forward_list<T> (singly-linked)

* Tek yönlü linked list; hafıza daha az; API azalmış (push_front, insert_after, erase_after).
* `splice_after` ile O(1) taşıma.

---

### E) std::array<T,N> ve C-Array

* Sabit derleme zamanı boyut; tüm üyeler O(1) erişim; contiguous.
* `std::array` modern C++ tercihidir çünkü STL uyumlu wrapper sağlar.

---

### F) Associative containers (std::set / std::map ve multimap/multiset)

**Temel:** Genelde kırmızı-siyah ağaç (balanced BST). Anahtarlar sıralıdır.

**Ortak üye fonksiyonlar:**

```cpp
insert(value) -> pair<iterator,bool> // bool indicates insertion success
emplace(args...)
find(key)
count(key)
lower_bound(key), upper_bound(key), equal_range(key)
erase(iterator) or erase(key)
key_comp(), value_comp()
```

**Karmaşıklık:** insert/find/erase O(log n) garantisi.

**Invalidation:** Insert genelde diğer iteratorleri bozmaz; erase sadece silinen iteratorü bozar.

**map özel notu:** `operator[]` yoksa varsayılan Value oluşturur — dikkat: okuma amaçlı kullanırken `find` tercih et.

**Kullanım örneği:** sıralı çıktıya ihtiyaç varsa (örn. tarih → kayıt), `map` kullan.

---

### G) Unordered associative containers

`std::unordered_map`, `std::unordered_set`

**Temel özellikler:**

* Hash tabanlı: ortalama O(1) insert/find/erase.
* Rehashing: container büyüyünce bucket sayısı artar ve **tüm iteratorler geçersizleşir**.
* `reserve(size)` ile rehash sayısını azalt, `max_load_factor` ile doluluk oranını kontrol et.

**Fonksiyonlar:** `bucket_count(), bucket_size(i), bucket(key), load_factor(), rehash(), reserve()` gibi hash-specific üyeler.

**Kullanım:** Hızlı erişim gerektiğinde; sıra önemli değilse `unordered_map` tercih edilir.

---

### H) Container adapters: stack, queue, priority_queue

* `std::stack<T,Container=deque<T>>`: LIFO, `push`, `pop`, `top`.
* `std::queue<T,Container=deque<T>>`: FIFO, `push`, `pop`, `front`, `back`.
* `std::priority_queue<T>`: heap tabanlı (max-heap by default). `top`, `push`, `pop`.

Adapter’ların arkasında vector/deque ya da list olabilir.

---

## 4) İteratörler — kategoriler, gereksinimler, örnekler

İteratör kategorileri ve hangi algoritmanın hangi kategoriyi istediği kritik:

* **Input iterator**: tek yönlü, tek pas (istream_iterator).
* **Output iterator**: yazma amaçlı (ostream_iterator, back_inserter).
* **Forward iterator**: tekrar okunabilir, ileri.
* **Bidirectional iterator**: ++ ve -- destekler (list, map).
* **Random access iterator**: pointer benzeri (vector, deque, array). `std::sort` random access ister.

**Örnek uyumluluk:** `std::sort` ➜ Random access; `std::stable_sort` ➜ random access; `std::list::sort()` üye fonksiyonu kullanılır çünkü list random-access sağlamaz.

**advance(it, n)**: complexity O(n) veya O(1) iterator tipine göre. Bu da algoritma seçiminde önem taşır.

---

## 5) STL Algoritmaları — kategori kategori derinlemesine

Aşağıda algoritmaların ne yaptığı, iterator gereksinimi, karmaşıklık ve önemli nüanslar ile örnekler.

### A) Non-modifying sequence operations

**find, find_if, count, count_if, mismatch, equal**

* **Girdi:** Forward iterator veya daha güçlü.
* **Karmaşıklık:** O(n)
* **Not:** `std::find` linear tarar; `std::binary_search` sıralı arama olup O(log n) ve **sıralı** veri ister.

**Örnek:**

```cpp
auto it = std::find_if(v.begin(), v.end(), [](int x){ return x%2==0; });
```

### B) Modifying sequence operations

**copy, copy_if, move, move_backward, fill, generate, remove, remove_if, replace, unique**

* **remove/remove_if:** Elemanları gerçekten silmez; aralığı yeniden düzenleyip yeni son iterator döner. Bu yüzden **erase–remove idiom** kullanılmalı.
* **Iterator requirement:** Forward iterator veya daha güçlü (copy için input/output vs gibi ayrıntılar var).

**erase–remove idiom detay:**

```cpp
v.erase(std::remove_if(v.begin(), v.end(), pred), v.end());
```

`remove_if` öğeleri öne kaydırır; `erase` geri kalan artık gereksiz olanları siler.

### C) Sorting & ordering

**sort, stable_sort, partial_sort, nth_element, is_sorted, is_sorted_until**

* `sort` ve `stable_sort` random-access iterator ister.
* `partial_sort` ilk k elemanı sıralı olarak getirir — k küçükse faydalı.
* `nth_element` ortadaki öğeyi doğru pozisyona getirir; kullanışlı median/top-k için (average O(n)).

**Örnek medyan:**

```cpp
std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
int median = v[v.size()/2];
```

### D) Set algorithms (iki sıralı aralık ile)

**set_union, set_intersection, set_difference, set_symmetric_difference, includes**

* **Girdi:** her iki aralık da **sıralı** olmalı.
* **Karmaşıklık:** O(n+m)

**Örnek:**

```cpp
std::set_union(a.begin(),a.end(), b.begin(),b.end(), std::back_inserter(out));
```

### E) Heap algorithms

**make_heap, push_heap, pop_heap, sort_heap**

* Heap algoritmaları `Random Access` iterator ister.
* `make_heap` O(n) — ilginç olarak linear zaman.
* `push_heap`/`pop_heap` O(log n).

**Örnek top-k:** küçük k için `make_heap` + `pop_heap` tekniği verimli.

### F) Numeric algorithms (<numeric>)

**accumulate, partial_sum, inner_product, iota**

* `accumulate` başlangıç değerine göre tip çıkarımı yapacağından dikkat: `accumulate(v.begin(), v.end(), 0LL)` gibi doğru başlangıç tipi ver.

### G) Partition / Permutations / Misc

**partition, stable_partition, next_permutation, prev_permutation, reverse, rotate, shuffle, sample**

* `partition` elemanları predicate'e göre iki blok hâline getirir; `stable_partition` göreli düzeni korur (daha maliyetli).
* `rotate` aralığı döndürür; kullanışlı ring buffer mantıkları için.

### H) Parallel algorithms (C++17+) ve Ranges (C++20)

* Çoğu algoritma `std::execution::par` gibi execution policy ile paralel çalıştırılabilir. **Dikkat:** fonksiyonların yan etkisiz (thread-safe) olması gerekir.
* Ranges (<ranges>) C++20 ile algoritmaları pipeline hâline getirir — readability artar.

---

## 6) Functors / Lambdas / std::function / Comparator — derinlemesine

**Functors**: sınıf wrapper'ı olan callable. Avantaj: state saklayabilir, inline fonksiyonel optimizasyon (inlining).

**Lambda**: kısa, yerel, genelde tercih edilir. Capture kuralları `[]`, `[&]`, `[=]`, `[this]` vs. vardır.

**std::function**: tip-eriyebilir (type-erased) callable; esneklik karşılığında hafif maliyet.

**Comparator kuralları:** Strict weak ordering olmalı (transitive ve consistent) yoksa `std::sort` undefined behavior'e yakın sonuç verebilir.

**Örnek comparator yanlışlığı:** comparator `{ return a.size() < b.size(); }` ve `==` durumunda tutarlılık bozulabilir — comparator `!(a<b) && !(b<a)` eşitlik tanımıyla uyumlu olmalı.

---

## 7) Emplace vs push, move semantics, perfect forwarding — detaylar + örnekler

**push_back(x)**: x kopyalanır veya taşınır.
**emplace_back(args...)**: doğrudan yerde nesne inşa eder.

**std::move**: lvalue’yi rvalue’ya çevirir; taşınma sonrası objenin durumu *geçerli ama belirsiz* olur — tekrar kullanmadan önce dikkat.

**Perfect forwarding**: `template<class T> void f(T&& t) { g(std::forward<T>(t)); }` ile hem lvalue hem rvalue doğru şekilde iletilir.

**Örnek:**

```cpp
struct Large { Large(int,int); Large(const Large&); Large(Large&&); };
std::vector<Large> v;
v.emplace_back(1,2); // daha verimli
```

---

## 8) Node handles, hints, rehash ve allocator notları (ileri)

**Node handles (C++17):** `extract()` ile bir node alınır ve başka bir container'a `insert(node)` ile konulabilir. Bu, hash/map’ler arasında hızlı taşımayı sağlar.

**Hints:** `map.insert(hint, value)` ile doğru hint verilirse amortize O(1) ekleme mümkün.

**Allocators:** Özel allocator yazarak bellek tahsisini kontrol et; yüksek performans uygulamalarında allocator tuning faydalı olabilir.

---

## 9) Pratik örnekler — gerçekçi, satır satır açıklama

Burada birkaç gerçek dünya örneği, kod ve adım adım açıklama verildi (canvas'ta örnekler var). Örnekler: kelime frekansı (unordered_map + reserve), top-k (heap teknikleri), tarih aralığı sorguları (map + lower_bound/upper_bound), erase–remove tipik hataları.

---

## 10) Cheat sheets: hızlı referans tablolar (membership, complexity, invalidation)

Canvas içinde kolayca bakabileceğin tablolar ekledim: **(1)** container -> önemli üye fonksiyon örnekleri, **(2)** container -> iterator invalidation özet, **(3)** algoritma -> required iterator category ve complexity.

---

## 11) Sık yapılan hatalar ve nasıl düzeltilirler (pattern’ler)

* **Hata:** `std::remove(v.begin(), v.end(), x);` (sonucu kullanmamak). **Çözüm:** `v.erase(std::remove(...), v.end());`
* **Hata:** `map[key]` sadece sorgulama için kullanılması (yan etki: yeni anahtar eklenir). **Çözüm:** `auto it = map.find(key); if (it != map.end()) ...`
* **Hata:** `std::sort` çağırıp `list` vermek. **Çözüm:** `list.sort()` veya vector’e taşıyıp sort et.
* **Hata:** Paralel algoritmada yan-etkili lambda kullanmak. **Çözüm:** saf, side-effect olmayan fonksiyon ya da thread-safe düzenlemeler kullan.

---

## 12) İleri seviye ve alıştırmalar

İleri konular: Ranges (views::filter/transform), paralel execution, özel allocator yazma, node handles ile konteyner taşımaları.

Önerilen alıştırma projeleri (aşamalı):

1. Kelime bulutu: `unordered_map<string,int>` + `partial_sort` ile top-k.
2. Tarih serisi sorgu motoru: `std::map<date, vector<Record>>`, `lower_bound/upper_bound` ile aralık sorguları.
3. Gerçek zamanlı task scheduler: `priority_queue` + custom comparator + fazladan data.
4. Memory tuning deneyleri: vector vs list vs deque benchmarkları (allocator varyasyonlarıyla).

---

### Son not

Belgeyi genişlettim — her konteynerin daha detaylı üye fonksiyonları, complexity ve invalidation kuralları, ve algoritmaların iterator gereksinimleri ile pratik örnekler eklenmiş durumda. Eğer istersen, şimdi doğrudan:

* **Her bir konteynerin tam üye fonksiyon listesi** (prototip + örnek) halinde ayrı dosyaya dökeyim, veya
* **Algoritmalar** için her birinin iterator gereksinimi + örnek kullanım + performans karşılaştırmasını içeren ayrı bir bölüm oluşturayım, veya
* Belgeyi **C++20 Ranges** kullanarak modern pipeline örnekleriyle zenginleştireyim.

Hangi adımı seçeyim — veya doğrudan belirli bir konteyner (ör. `vector` veya `unordered_map`) ya da algoritma (ör. `nth_element`, `partial_sort`, `remove_if`) üzerinde derinleşeyim?


