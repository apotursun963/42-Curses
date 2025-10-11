
# Container
container (kap) kavramı, veri yapılarının temelini oluşturur.
Bir container, C++’ta çok sayıda veriyi depolamak, yönetmek ve onlara erişmek için kullanılan bir sınıftır.
Yani, bir “veri kutusu” gibidir.

## Container Türleri
C++’ta container’lar, Standard Template Library (STL) içinde bulunur ve üç ana kategoriye ayrılır.

### 1. Sequence Containers (Sıralı Kaplar)
Verileri belirli bir sırayla saklarlar.
| Container      | Açıklama                                                          |
| -------------- | ----------------------------------------------------------------- |
| `vector`       | dinamik olarak büyüyüp küçülebilen bir dizi (array) türüdür.      |
| `deque`        | Hem baştan hem sondan ekleme/silme yapabilirsin.                  |
| `list`         | Çift yönlü bağlı listedir. Ortadan da hızlı ekleme/silme yapılır. |
| `array`        | Sabit boyutlu dizidir. (C++11’den itibaren)                       |
| `forward_list` | Tek yönlü bağlı listedir. Hafif ama tek yönde gezinilebilir.      |

### 2. Associative Containers (Eşleme Kapları)
### 3. Unordered Containers (Sırasız Kaplar)
