
# UNIX sinyalleri nedir ve nasıl çalışır ?  
-------------------------------------------
UNIX sinyalleri, bir UNIX işletim sistemi içinde süreçler (process) arasında iletişimi ve işlemleri kontrol etme mekanizmalarını sağlar. UNIX sinyalleri, genellikle sistemin veya kullanıcı tarafından bir işlem üzerinde gerçekleştirilen işlemleri iletmek veya kontrol etmek için kullanılır. 

## Signal (Sinyal):
Sinyal, işletim sisteminde çalışan bir sürecee (process'e) gönderilen bir mesajdır.
işletim sistemi, sinyalleri süreçler arasında iletişim sağalmak veya bir süreci kontorl etmek için kullanır.
Sinyaller, bir sürece belirli bir olayın meydana geldiğini bildiren mekanizmalardır. Örneğin: 
Süreci durdurmak, sonlandırmak veya hata durumu oluştuğunda bir sinyal gönderilebilir.
özetle, Sinyal Süreçlere mesaj göndermek için kullanılan bir **iletişim yöntemidir**.

### Sinyal Türleri:
- **Sonlandırma Sinyalleri**:
    - SIGTERM (SN: 15): Süreci düzgün bir şekilde sonlandırır.
    - SIGKILL (SN: 9) : Süreci anında sonlandırır (geri döndürülemez) ve süreç tarafından yakalanamaz.

- **Duraklatma ve Devam Ettirme Sinyalleri**:
    - SIGSTOP (SN: 17): Süreci duraklatır.
    - SIGCONT (SN: 19): Duraklatılan süreci devam ettirir.

- **Kesme ve Bırakma Sinyalleri**:
    - SIGHUP (SN: 1): Terminal bağlantısı kapandığında veya uzak bağlantı sona erdiğinde gönderilir.
    - SIGINT (SN: 2): Kullanıcı tarafından programın sürecinin **kesilmesi**. (**CTRL+C**)

- **Hata Bildirim Sinyalleri**:
    - SIGSEGV (SN: 11): Geçersiz bellek erişimi.
    - SIGILL (SN: 4): Geçersiz bir işlem kodu yürütme girişimi.

- **Özel Kullanıcı Sinyalleri**:
    - SIGUSR1, SIGUSR2: Kullanıcı tarafından tanımlanan özel amaçlar için kullanılır.

Daha fazla sinyal türleri için >> [Signal-Types](https://www.math.stonybrook.edu/~ccc/dfc/dfc/signals.html)

### Sinyal İşleme Fonksyiyonları:
- `kill` (`Sender`):
    - Görev: Bir sürece (**process**) bir sinyal göndermek için kullanılır.
    - Kullanımı: **kill** işlevi, belirtilen sürecin kimliğine (`PID`) belirli bir sinyal gönderir.
    - Prototip: `kill(pid_t pid, int sig);`

- `signal` (`Reciever`):
    - Görev: Belirtilen bir sinyali yakalamak için kullanılır.
    - Kullanımı: **signal** işlevi, belirli bir sinyal geldiğinde çalışacak bir **handler** fonkisyonu belirler.
    - Prototip: `signal(int sig, void(*handler)(int));`

- `getpid`: 
    - Görev: Çalışmakta olan sürecin (`process`) kimliğini (`PID`) döndürüyor.
    - Kullanımı: `getpid` işlevi, çalışmakta olan bir sürecin, **process ID'sini** döndürür.
    - Prototip: `getpid(void);`

- `pause`: 
    - Görev: Belirli bir sinyal alana kadar süreci durdurur.
    - Kullanımı: `pause` işlevi, belirli bir sinyal gelene kadar işlemi durdurur. Bu sinyal geldiğinde işleyici `signal handler` fonksiyon çağrılır.
    - Prototip: `pause(void);`

- `sleep`: 
    - Görev: Belirtilen süre boyunca işlemi uyutmak için kullanılır.
    - Kullanımı: `sleep` işlevi, belirli bir süre boyunca işlemi uyutur. Bu süre boyunca işlem kontrolü devretmez.
    - Prototip: `sleep(unsigned int seconds);`

- `exit`:
    - Görev: Bir programı sonlandırmak için kullanılan bir fonksiyondur. 
    - Kullanımı: **exit(0)**, Program başarıyla sonlandırıldığında, işletim sistemine başarı mesaj gönderir.
    - Prototip: `void exit(int status)`
