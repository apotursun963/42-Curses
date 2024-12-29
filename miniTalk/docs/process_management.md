
# Process (Süreç):
Süreç, bir işletim sistemi tarafından yönetilen ve yürütülen bir **aktif** programdır.
yani, Süreç Bir işletim sisteminde aktif olarak çalışan bir program.
`ps -u` komutu, sistemdeki kullanıcıların yürütmekte olduğu tüm işlemleri (process) listelemek için kullanılan bir komuttur.

## Süreçlerin temel özellikleri:
- **Benzersiz Kimlik (Process ID - PID)**:
    - Her sürecin işletim sistemi tarafından atanan benzersiz bir **kimliği** vardır. PID, süreçleri tanımlamak ve yönetmek için kullanılır.

- **Bağımsız Bellek Alanı**:
    - Her süreç, kendi bellek alanına sahiptir. Bu, süreçlerin birbirinin belleğine müdahale etmesini önler.
        - Kod Bölgesi: Programın çalıştırılabilir talimatları burada yer alır.
        - Yığın (Stack): Fonksiyon çağrıları ve yerel değişkenler için kullanılır.
        - Küme (Heap): Dinamik bellek tahsisi burada gerçekleşir.

- **Ebeveyn - Çocuk İlişkisi (Parent - Child)**:
    - Bir süreç başka bir süreci başlatabilir. yeni başlatılan süreç **çocuk süreç** olarak adlandırılır. ve başlatan süreç **ebeveyn süreç**'tir. 

        - Ebeveyn Süreç (Parent Process): Ebeveyn süreç, bir işletim sisteminde başka bir süreç (çocuk süreç) oluşturan süreçtir. Ebeveyn süreç, çocuk sürecin başlatılmasından `fork` ve yönetiminden sorumlu olup, aynı zamanda kendi görevlerini de yerine getirebilir. Ebeveyn süreç, `wait` çağrılarını kullanarak çocuk sürecin tamamlanmasını bekler. ve gerektiğinde çocuk süreci durdurabilir veya tamamen sonlandırabilir. `kill`

        - Çocuk Süreç (Child Process): Çocuk süreç, bir işletim sisteminde başka bir süreç (ebeveyn süreç) tarafından oluşturulan bir süreçtir. Çocuk süreç, başlangıçta ebeveyn sürecin bir kopyasıdır ve genellikle ebeveynin belirlediği görevleri yerine getirmek için çalışır. Çocuk süreçler, ebeveyn süreçle aynı sistem kaynaklarını paylaşabilir veya bağımsız olarak çalışabilir. Çocuk sürecin, benzersiz bir süreç kimliğine (Process ID - PID) sahiptir. Ebeveyn sürecin PID'si, çocuk sürecin ebeveyn kimliği (Parent PID - PPID) olarak saklanır. Çocuk süreç, görevini tamamladıktan sonra sona erer. Tamamlandığında, çıkış kodunu ebeveyn sürece iletir.

- **Sonlanma (Termination)**:
    - Bir süreç (process), yaşam döngüsünü tamamladıktan sonra veya beklenmedik bir durum sonucunda sona erer. Bu, işletim sistemi tarafından süreç kaynaklarının serbest bırakılmasıyla sonuçlanır. Bir sürecin sonlanması, planlanmış bir görev tamamlanmasıyla olabileceği gibi, hata durumları veya dış müdahaleler nedeniyle de gerçekleşebilir.

        - Süreçlerin Sonlanma Nedenleri:
            - Görevin Tamamlanması (Normal Sonlanma): Süreç, görevini başarıyla tamamladığında doğal bir şekilde sona erer. Süreç, bir çıkış durumu (exit status) döndürür ve kaynakları serbest bırakır.

            - Hata Durumu (Beklenmeyen Sonlanma): Süreç, bir hata durumu nedeniyle beklenmedik bir şekilde sona erebilir. Hatalar, program kodunda veya dış etkenlerde oluşabilir. Süreç, bir hata koduyla sonlanır ve hata türü işletim sistemine rapor edilir.

            - Kullanıcı veya İşletim Sistemi Tarafından Sonlandırılma: Süreç, dış bir müdahale ile sonlandırılabilir. Kullanıcı, terminalde kill veya Ctrl+C gibi komutlarla süreci sonlandırır. veya İşletim sistemi, kaynak yetersizliği veya yönetim politikaları nedeniyle bir süreci sonlandırabilir. ayrıca süreç sonlandırmaları `sinyaller` yoluyla da gerçekleştirilebilir.

![process-img](https://learnloner.com/wp-content/uploads/2023/05/Process-Management-In-OS.png.webp)