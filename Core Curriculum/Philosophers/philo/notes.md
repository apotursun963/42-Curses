
# Philosophers

## Proje Açıklaması
Bir veya daha fazla filozof, yuvarlak bir masada oturur. Masanın ortasında büyük bir spagetti kasesi bulunur.  

- Filozoflar sırayla **yemek yer**, **düşünür** veya **uyurlar**.  
  - Yemek yerken ne düşünürler ne de uyurlar.  
  - Düşünürken ne yemek yerler ne de uyurlar.  
  - Uyurken ne yemek yerler ne de düşünürler.  

- Masada, filozof sayısı kadar çatal bulunur.  
- Spagettiyi tek çatal ile yemek zor olduğundan, bir filozof yemek yemek için hem sağındaki hem de solundaki çatalı alır.  
- Yemek yeme işlemi bitince, çatalını masaya geri koyar ve uyumaya başlar. Uyandığında tekrar düşünmeye koyulur. Simülasyon, bir filozof açlıktan öldüğünde sona erer.  

Kurallar:  
- Her filozof yemek yemelidir ve açlıktan ölmemelidir.  
- Filozoflar birbirleriyle konuşmaz.  
- Bir başka filozofun ölüp ölmeyeceğini bilemezler.  
- Açlıktan ölmemek temel önceliktir!

### Genel Kurallar
- Program aşağıdaki argümanları almalıdır:  
  ```
  number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  ```  
  - **number_of_philosophers**: Filozofların ve çatalların sayısı.  
  - **time_to_die (milisaniye cinsinden)**: Bir filozof, son yemeğine veya simülasyonun başlangıcına göre `time_to_die` milisaniye içinde yemek yemeye başlamazsa ölür.  
  - **time_to_eat (milisaniye cinsinden)**: Bir filozofun yemek yemesi için geçen süredir. Bu süre boyunca iki çatalı da tutmalıdır.  
  - **time_to_sleep (milisaniye cinsinden)**: Bir filozofun uyuyarak geçirdiği süredir.  
  - **number_of_times_each_philosopher_must_eat (isteğe bağlı argüman)**: Eğer tüm filozoflar en az bu kadar yemek yemişse, simülasyon durur. Belirtilmezse, simülasyon bir filozof ölünce sona erer.  

- Her filozofun **1’den number_of_philosophers’a kadar bir numarası vardır.**  
- **Filozof 1**, **filozof number_of_philosophers’ın** yanına oturur.  
- Diğer tüm filozoflar, **N numaralı filozof, N - 1 ve N + 1 numaralı filozofların arasına oturur.**  

### **Programın Günlüğü (Log Mesajları)**
Her filozofun durum değişiklikleri şu formatta olmalıdır:  
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
- `timestamp_in_ms` şu anki zaman damgasını (milisaniye cinsinden) temsil eder.  
- `X`, filozofun numarasıdır.  
- **Bir mesaj başka bir mesajla karışmamalıdır.**  
- **Bir filozofun öldüğünü belirten mesaj, ölümünden en fazla 10 ms sonra gösterilmelidir.**  
- **Filozofların ölmemesi sağlanmalıdır!**  
- **Program veri yarışlarını (data race) önlemelidir.**

## Zorunlu Kısım
- Her filozof bir **thread** olmalıdır.  
- Her iki filozofun arasında bir çatal bulunur. Bu nedenle, birden fazla filozof varsa, her filozofun sol tarafında ve sağ tarafında bir çatal olur. Eğer yalnızca bir filozof varsa, masada yalnızca bir çatal bulunmalıdır.  
- Filozofların çatalı birden fazla kez almasını önlemek için, her çatalın durumunu bir **mutex** ile korumalısınız.

| **Program Adı**   | philo |
|-------------------|-------|  
| **Teslim Edilecek Dosyalar** | Makefile, *.h, *.c (philo/ dizininde) |  
| **Makefile Hedefleri** | NAME, all, clean, fclean, re |  
| **Argümanlar** | number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat] |  
| **Harici Fonksiyonlar** | memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |  
| **Libft Kullanımı** | Hayır |  
| **Açıklama** | Thread'ler ve mutex'ler kullanılarak filozofların simülasyonu |  