
/usr/bin: Burada (ls, cat ...) gibi komutların dosyalarının bulunduğu bir yerdir.
ayrıca sistem araçları, programlar ve uygulamalar ve scriptler bulunur

PATH Değişkeni Nedir ?
Bir ortam değişkenidir (env var) ve sistemin komutları veya programları, scriptler bulunur.
Eğer PATH olmasaydı, her komutun tam yolunu yazmak zorunda kalırdık, bu da kullanımı çok daha zor ve zahmetli hale getirirdi. PATH sayesinde, sistem belirli dizinleri otomatik olarak tarar ve komutları sadece adını yazarak çalıştırmamıza izin verir.
Bir komut çalıştırdığında, sistem sırasıyla bu dizinlere bakar ve komutun olup olmadığını kontrol eder.
Eğer komut bu dizinlerden birinde varsa çalıştırılır, yoksa "command not found" hatası alınır.
Bir script veya program PATH içindeki bir dizine taşınırsa, her yerden kolayca çalıştırılabilir.
Eğer PATH içinde değilse, tam dizin yolunu yazmadan çalıştırılamaz.

Eğer bir script veya program PATH içinde olmayan bir dizinde bulunuyorsa, doğrudan ismiyle çalıştırılamaz. 
Geçerli dizindeki bir script’i çalıştırmak için . (nokta), geçerli çalışma dizinini temsil eder. ./mycmd komutu, o an bulunduğun dizindeki "mycmd" adlı scripti çalıştırır.

Eğer bir script PATH içinde değilse, ./script_adı ile çalıştırabilirsin. Ya da tam dizin yolunu yazarak çalıştırabilirsin.
Ama sadece ismini yazarak çalıştırmak için onu PATH içindeki bir dizine taşımalısın
- which komutların nerede olduğunu belirtiyor.


Ortam Değişkenleri nedir (enviroment variable) ?
Ortam değişkenleri (Environment Variables), işletim sisteminde çalışan kullanıcı oturumlarına, programlara ve scriptlere çeşitli bilgiler sağlayan değişkenlerdir.

- Sistemdeki programların çalışmasını yönlendirmek
- Kullanıcı bilgilerini ve ayarlarını saklamak
- Programların ve scriptlerin ihtiyaç duyduğu yolları belirlemek
- Güvenliğe katkı sağlamak (örneğin, özel bilgiler şifreli değişkenlerde saklanabilir)

bir ortam değişkeni oluşturmak için;
export VAR=test
ortam değişkenlerinin kalıcı olması için .bashrc içine girip bazı ayarlamaları yapmamız gerekiyor


Sinyaller
---------
- Ctrl+C: Yeni Bir Satırda Yeni bir **prompt** gösterir. Yani, **SIGINT** Sinyalini gönderir, ki bu sinyal terminale işlemi *Dur, yani sonlandır* anlamına gelir.

- Ctrl+D: Boş bir Satırda bu sinyal, "dosya sonu" (EOF - End Of File) sinyalini gönderir ve program sona erer.

- Ctrl+\: Bu ise, bir "quit" sinyali (SIGQUIT) gönderir ve çalışan bir programı zorla kapatabilir. ama bizden istediği hiç bir şey yapmamamız.

Redirections (Yönlendirmeler)
-----------------------------
- < (Input Redirection - Girdi Yönlendirme):
Bir komutun girdisini bir dosyadan alır. yani dosyayı (girdiyi) komuta yönlendiriyor.
    - cat < apo.txt || wc -l < apo.txt

- > (Output Redirection - Çıktı Yönlendirme)
Bir komutun çıktısını bir dosyaya yazar (dosya varsa üzerine yazar).
    - echo "merhaba" > apo.txt

- << (Heredoc - Delimiter ile Girdi Alma)
Kullanıcıdan bir bitiş kelimesine (delimiter) kadar satır satır girdi alır, ama geçmişe (history) eklemez.
Heredoc, kabukta (shell) kullanıcıdan bir bitiş kelimesine (delimiter) kadar çok satırlı metin girdisi almayı sağlayan bir yöntemdir.
    - cat << EOF || wc -l << end

- >> (Append Output Redirection - Çıktıyı Ekleme Modunda Yönlendirme)
Bir komutun çıktısını, bir dosyaya yazar, ama üzerine yazmaz, mevcut içeriğin sonuna ekler.
    - echo "Yeni" >> apo.txt


// https://github.com/alexnik42/minishell/tree/main