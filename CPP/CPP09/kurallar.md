

Bu metin, modül boyunca yapılacak egzersizler için uyulması gereken **zorunlu kuralları** anlatıyor. Her egzersizde C++’ın standart container’larını kullanmak mecburi. Bir container bir egzersizde kullanıldıktan sonra, modülün geri kalanında **tekrar kullanılamaz**. Egzersizlere başlamadan önce tüm konu metninin baştan sona okunması tavsiye ediliyor. Her egzersizde en az bir container kullanılmalı; ancak **02 numaralı egzersiz** bunun istisnası ve bu egzersizde **iki farklı container** kullanılması zorunlu.

Her program için ayrı bir Makefile teslim edilmesi gerekiyor. Bu Makefile, kaynak dosyaları derleyip istenen çıktıyı üretmeli ve derleme sırasında `-Wall`, `-Wextra` ve `-Werror` bayraklarını kullanmalı. Kodun C++ ile yazılması şart ve Makefile gereksiz yere yeniden derleme (relink) yapmamalı. Ayrıca Makefile içinde en az `$(NAME)`, `all`, `clean`, `fclean` ve `re` kurallarının bulunması zorunlu.

