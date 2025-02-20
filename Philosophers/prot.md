# Thread fonksiyonlarını prototipleri

| **Fonksiyon**           | **Açıklama**  |
|-------------------------|--------------|
| `pthread_create`       | Yeni bir thread (iş parçacığı) oluşturur ve verilen fonksiyonu bu thread içinde çalıştırır. |
| `pthread_join`         | Belirtilen thread’in bitmesini bekler, böylece ana thread bu thread tamamlanmadan devam etmez. |
| `pthread_detach`       | Thread’i bağımsız hale getirir, böylece tamamlandığında sistem kaynakları otomatik olarak serbest bırakılır. |
| `pthread_mutex_init`   | Mutex (karşılıklı dışlama kilidi) başlatır ve thread’ler arası senkronizasyon için kullanılır. |
| `pthread_mutex_destroy`| Kullanımı bitmiş olan bir mutex’i yok eder ve sistem kaynaklarını geri serbest bırakır. |
| `pthread_mutex_lock`   | Mutex’i kilitleyerek thread’in belirli bir kaynağa erişmesini sağlar, diğer thread’ler bekler. |
| `pthread_mutex_unlock` | Daha önce kilitlenmiş bir mutex’i serbest bırakarak diğer thread’lerin kaynağa erişmesine izin verir. |