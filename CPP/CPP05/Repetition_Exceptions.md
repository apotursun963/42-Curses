

Repetition (Tekrar)
C++’ta tekrar kavramı, belirli bir kod bloğunu birden fazla kez çalıştırmak anlamına gelir. Bunun için döngüler (loops) kullanılır.

Exceptions (İstisnalar)
Exception, program çalışırken ortaya çıkan hata durumlarını yakalayıp yönetme mekanizmasıdır.
Normalde bir hata olduğunda program çöker ama exceptions sayesinde:
- Hatayı yakalayabiliriz
- Kullanıcıya anlamlı mesaj verebiliriz
- Programı kontrollü şekilde sonlandırabiliriz
Bir hata oluştuğunda programı aniden sonlandırmak yerine, C++ istisnalar oluşturmanıza ve bunları yakalayıp düzgün bir şekilde işlemenize olanak tanır.
Anahtar Kelimeler (try, throw, catch)


C++'da İstisna (Exception) İşleme Nasıl Çalışır?
---
1. Throwing an Exception (Bir İstisna Atma)
Bir hata veya beklenmeyen bir durum oluştuğunda program throw istisnayı işaret etmek için anahtar kelimeyi kullanır.

2. Catching an Exception (Bir İstisnayı Yakalamak)
Program, fırlatılan (throw edilen) istisnayı yakalayıp işlemek için uygun bir catch bloğu arar.

3. Handling the Exception (İstisnanın Ele Alınması)
Catch bloğu, hataya yanıt vermek için gerekli mantığı içerir ve programın ya toparlanmasına ya da düzgün bir şekilde sonlanmasına imkân tanır.
