


/*
Thread (İş Parçacığı)
Thread, bir programın içinde bağımsız olarak çalışabilen en küçük yürütme birimidir. 
Bir işlem (process) içinde birden fazla thread bulunabilir ve bu thread'ler 
aynı bellek alanını paylaşarak çalışır.

Thread Kullanımının Avantajları:
Paralel işlem yapmayı sağlar: Aynı anda birden fazla işin yürütülmesine olanak tanır.
Daha düşük maliyetlidir: İşlemler (process) gibi tamamen yeni bellek alanı tahsis etmez, aynı bellek alanını paylaşarak çalışır.
Ancak, thread'ler süreçler (process) gibi birbirlerinden tamamen bağımsız değildir. 
Aynı süreç içinde çalıştıkları için bir thread'in yaptığı değişiklik diğer thread'leri etkileyebilir.


Mutex (Karşılıklı Dışlama, Mutual Exclusion)
Mutex, çoklu iş parçacıklarının (thread) bir kaynağa 
aynı anda erişmesini engelleyen bir senkronizasyon
(birden fazla işlemin belirli bir düzen içinde çalışmasını sağlama sürecidir. ) aracıdır.
Yani, bir iş parçacığı bir kaynağa erişmeye başladığında, o kaynağa diğer 
iş parçacıkları tarafından aynı anda erişilmesini engeller. 
İş parçacığı kaynağı serbest bıraktığında, diğer iş parçacıkları kaynağa erişebilir.
Bu, veri tutarsızlığını önler ve güvenli erişimi sağlar.


Özetle:
Thread: İşlemi birden fazla parçaya bölerek aynı anda çalıştırır, böylece işlem süresini kısaltır.
Mutex: Ortak kaynaklara erişimde senkronizasyon sağlayarak çakışmaları önler.


Thread'lerin Paralel Çalışması Nasıl Gerçekleşir?
Thread'lerin paralel çalışmasını sağlayan temel mekanizmalardan 
biri sleep(1); fonksiyonudur. Bu fonksiyon, thread'in CPU'yu belirli 
bir süre serbest bırakmasını sağlar ve işletim sistemi başka bir thread'i çalıştırabilir.

Örnek İşleyiş:
t1 başlar: "Thread 1: 1" yazdırır, ardından sleep(1) ile beklemeye geçer.
İşletim sistemi CPU'yu t2'ye verir.
t2 başlar: "Thread 2: A" yazdırır, ardından sleep(1) ile beklemeye geçer.
t1 devam eder: "Thread 1: 2" yazdırır, tekrar sleep(1) ile beklemeye geçer.
İşletim sistemi t2'yi çalıştırır.
t2 devam eder: "Thread 2: B" yazdırır, tekrar sleep(1) ile beklemeye geçer.
Bu döngü devam ederek thread'lerin birbirlerine geçiş yapmasını ve paralel bir şekilde çalışmasını sağlar.

günlük hayattan örnek:
Thread (İş Parçacığı):
Bir programda aynı anda farklı işler yapan bağımsız birimlere thread denir. 
Örneğin, bir inşaatta bir işçi temeli kazarken diğeri duvarı örüyor, her biri bir thread gibi çalışır.

Mutex (Karşılıklı Dışlama Kilidi):
Bir kaynağa (örneğin, bir inşaat malzemesi) aynı anda sadece bir thread’in erişmesini sağlar. 
Örneğin, inşaatta bir işçi merdiveni kullanıyorsa, diğerleri sırayla bekler. 
Mutex, bu sırayı kontrol eder ve çakışmaları önler.

*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>



void    *func(void *)
{
    printf("apo\n");
    usleep(1000);
    printf("trs\n");
}


int main(int argc, char **argv)
{
    pthread_t   t1, t2;

    pthread_create(&t1, NULL, &func, NULL);
    pthread_create(&t2, NULL, &func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}




/*
Mutex kullanmadığında yarış durumu (race condition) oluşuyor. 
İki thread aynı anda increment++ işlemini yaparken birbirinin güncellemelerini bozabiliyor. 
Bu yüzden sonuç her çalıştırmada farklı olabiliyor.

Mutex kullandığında, her seferinde sadece bir thread increment değerini değiştirebiliyor. 
pthread_mutex_lock() ile kilitleniyor, işlem yapılıyor, sonra pthread_mutex_unlock() ile açılıyor. 
Bu sayede işlemler sıralı yapılıyor ve increment her zaman doğru şekilde 200 oluyor.
*/

int increment = 0;
pthread_mutex_t mutex;

void    *increase(void *arg)
{
    char *thread_name = (char *)arg;

    for (int i=0; i < 15; i++)
    {
        pthread_mutex_lock(&mutex);
        increment++;
        pthread_mutex_unlock(&mutex);
        printf("%s %d\n", thread_name, increment);
        usleep(500);     // bunu kullandığımızda önce bir thread bitiyor sonra bir sonraki threade geçiyor
                                // yani paralel işlem yok bunu kullanmazsak
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_t   t1, t2;                 // Thread tanımlama

    pthread_mutex_init(&mutex, NULL);   // mutex init etme

    pthread_create(&t1, NULL, increase, (void *)"Bir");  // Thread oluşturma
    pthread_create(&t2, NULL, increase, (void *)"iki");

    pthread_join(t1, NULL);         // Thread'lerin tamamlanmasını bekleme
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);      // kullandığım mutexi yok ettim free gibi

    printf("Final increment value: %d\n", increment);
    return (0);
}
