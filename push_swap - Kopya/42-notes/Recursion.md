
# Recursive (Özyinelemeli) Fonksiyonlar

Recursive (özyinelemeli) bir fonksiyon, kendisini çağıran bir fonksiyondur. 
Recursive bir yapının çalışması, bir temel durum (base case) ve bir recursive çağrı içerir:

- **Temel Durum (Base Case):** Recursive çağrıların duracağı durumdur.
- **Recursive Çağrı:** Problem daha küçük alt problemlere bölünerek fonksiyon kendini çağırır.

## Recursive Mantıkta Bellek Analizi

Recursive mantıkta, her fonksiyon çağrısı, bir çağrı yığınına (call stack) eklenir. 
Bu çağrı yığını, işlemin sırasını ve her çağrı için gerekli değişkenleri takip eder.

### Çağrı Yığını Nedir?

Çağrı yığını, programın çalışması sırasında fonksiyon çağrılarının sırasını ve her çağrı için gerekli 
olan yerel değişkenleri saklayan bir veri yapısıdır. 
Yığın mantığıyla çalışır: Son giren ilk çıkar (LIFO).

### Örnek: Faktoriyel(3)'ü Ele Alalım.

#### Adım Adım Çalışma:
- **Başlangıç Çağrısı:**
    - `faktoriyel(3)` çağrılır.
    - `n = 3` olarak yığına eklenir. Sonuç beklenir.

- **İlk Recursive Çağrı:**
    - `faktoriyel(3)` içinde `faktoriyel(2)` çağrılır.
    - `n = 2` yığına eklenir. Sonuç beklenir.

- **İkinci Recursive Çağrı:**
    - `faktoriyel(2)` içinde `faktoriyel(1)` çağrılır.
    - `n = 1` yığına eklenir. Sonuç beklenir.

- **Üçüncü Recursive Çağrı:**
    - `faktoriyel(1)` içinde `faktoriyel(0)` çağrılır.
    - `n = 0` yığına eklenir.

- **Temel Durum:**
    - `faktoriyel(0)` temel duruma ulaşır ve 1 döndürür.
    - `faktoriyel(0)` yığından çıkar.

- **Sonuçların Geri Çözülmesi:**
    - `faktoriyel(1)` sonucu hesaplar: `1 * 1 = 1` ve yığından çıkar.
    - `faktoriyel(2)` sonucu hesaplar: `2 * 1 = 2` ve yığından çıkar.
    - `faktoriyel(3)` sonucu hesaplar: `3 * 2 = 6` ve yığından çıkar.

#### Her Recursive Çağrı:
- Yığına yeni bir fonksiyon çerçevesi (stack frame) eklenir.
- Her çerçeve, çağrı sırasında kullanılan yerel değişkenleri (n gibi) ve çağrının hangi aşamada olduğunu saklar.

#### Temel Duruma Ulaşınca:
- Fonksiyonlar birer birer yığından çıkar.
- Sonuçlar geri çözülür.

### Stack Overflow Riski:
- Çok derin recursive çağrılarda (örneğin, `faktoriyel(10000)`), çağrı yığını tükenebilir.
- Bu durumda stack overflow hatası oluşur.

---

## Recursive (Özyinelemeli) ve Iterative (Döngüsel) Yapılar

### 1. Recursive (Özyinelemeli):
- Bir fonksiyonun kendisini çağırarak problemi çözmesi. Problemi alt problemlere ayırarak çözer.
- Genellikle daha kısa ve anlaşılır.
- Her çağrı için çağrı yığınına bir giriş yapılır, bu yüzden daha fazla bellek kullanabilir.
- Çok derin çağrılarda **stack overflow** riski taşır.

### 2. Iterative (Döngüsel):
- Döngüler (for, while) kullanılarak problemi çözmesi. Döngülerle işlemi tekrarlar.
- Daha uzun olabilir, ancak performans açısından genelde daha verimlidir.
- Sabit bir bellek kullanır, çağrı yığını oluşturulmaz.
- Büyük veri setleri veya uzun işlemler için daha verimlidir.

**İterasyon (Iterate etmek):** Bir veri kümesi (arr, list) üzerindeki her bir öğeyi sırayla işlemek veya döngüyle tekrarlamak demektir. Örneğin, bir döngüyle dizideki tüm elemanları toplamak bir iterasyondur.

---

## Yığın (Stack) ve Bellek Yapısı

### Bellek Düzeni
Bellek, temel olarak birkaç farklı bölüme ayrılır. 
"Kodlar" ve "global" değişkenler genellikle belleğin alt kısmında, daha düşük adreslerde yer alır. 
Bu bölümler "sabittir", yani boyutları değişmez; hep aynı kalırlar. 
Ancak, boyutu değişebilen iki önemli bölüm vardır: **"Heap"** ve **"Stack"**, ve bunların boyutu **dinamiktir**.

### Heap:
Heap, belleğin alt kısımlarında yer alır ve program sırasında dinamik olarak bellekte yer ayırdığımız yerleri temsil eder. 
Örneğin, C dilinde `malloc`, `calloc`, `realloc` gibi fonksiyonlarla, ya da C++ dilinde `new` ile bellek ayırdığımızda bu alan heap üzerinde oluşturulur. 
Heap yukarı doğru büyür; yani daha fazla bellek ayırdıkça heap genişler.

### Stack:
Stack, belleğin üst kısmında yer alır. Stack, yerel değişkenlerimizi ve fonksiyon argümanlarımızı depolamak için kullanılır. İlginç bir şekilde, stack aşağı doğru büyür. 
Yani, heap yukarı doğru genişlerken stack aşağı doğru genişler. Bu şekilde, ikisi birbirine zıt yönlerde büyüdüklerinden aralarında yeterli alan sağlanmış olur.

Her fonksiyon çağrıldığında, stack’e bir stack frame adı verilen bir bellek bloğu eklenir. Bu blok şunları içerir:
- Fonksiyonun argümanları,
- Fonksiyonun yerel değişkenleri,
- Ve en önemlisi, dönüş adresi (fonksiyonun tamamlandıktan sonra geri döneceği yer).

### Stack’in Temizlenmesi:
Bir fonksiyon tamamlandığında, stack’ten ilgili stack frame kaldırılır. Aslında kaldırmak demek biraz yanıltıcı olabilir. Yapılan işlem, stack pointer'ın yukarı taşınmasıdır. 
Stack pointer, stack'in üst kısmını işaret eder. Yeni bir fonksiyon çağrıldığında, eski stack frame üzerine yeni veriler yazılır. Bu işlem oldukça verimli ve düzenlidir.

![memroy-layout](https://images.javatpoint.com/cpages/images/memory-layout-in-c.png)

---

## Stack Overflow Nedir?

Stack Overflow, bir programın stack belleği (RAM'deki bir bölüm) tahsis edilen sınırlarını aştığında ortaya çıkar. Bu durum, genellikle şu iki durumdan biri nedeniyle oluşur:

- **Sonsuz Rekürsiyon (Infinite Recursion):** Bir fonksiyon sürekli kendini çağırır ve her çağrıda stack'e yeni bir veri ekler.
- **Büyük Yerel Değişkenler (Large Local Variables):** Çok büyük yerel değişkenler kullanılır ve stack hızlı bir şekilde dolar.

### Stack Overflow’un Çalışma Mantığı:
Her fonksiyon çağrıldığında, stack frame adı verilen bir bellek bloğu stack’e eklenir. Bu blokta, fonksiyonun yerel değişkenleri, argümanları ve dönüş adresi saklanır. 
Eğer bir fonksiyon kendini sonsuz kez çağırırsa veya çok büyük yerel değişkenler eklenirse, stack hızla dolar. Belleğin sonuna ulaşıldığında, işletim sistemi Stack Overflow hatası verir ve program çöker.


## Recursive Fonksiyon
```C
int factorial(int num)
{
    if (num == 0)
        return (1);
    return (num * factorial(num - 1));
}
```

## Iterative Fonksiyon
```C
int factorial(int num)
{
    int res = 1;
    for (int i=0; i <= num; i++)
        res *= i;
    return (i);
}
```