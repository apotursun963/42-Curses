
# inception
Bu proje, Docker kullanarak sistem yönetimi bilginizi genişletmeyi amaçlamaktadır.
Yeni kişisel sanal makinenizde çeşitli Docker imajlarını sanallaştıracaksınız.

## Genel yönergeler
- Proje VM (Sanal Makine) üzerinde yapılmalı.
- Projenizin yapılandırması (configuration ) için gerekli tüm dosyalar **srcs** klasörüne yerleştirilmelidir.
- Bir Makefile da gereklidir ve dizininizin kök dizininde bulunmalıdır. Bu dosya, uygulamanızın tamamını kurmalıdır (yani, docker-compose.yml kullanarak Docker imajlarını oluşturmalıdır).


## Mandatory part
- Bu proje belirli kurallar altında farklı servislerden oluşan küçük bir altyapı kurmanızı istiyor.
- Tüm Proje Sana Makine'de Yapılacak. ***Docker Compose*** kullanmamız gerekiyor.

- Her Docker imagı'nın adı, ilgili servisin adıyla aynı ada sahip olması gerekir.
- Her servis kendine ait container içinde çalışması (run) gerekiyor.
- Performans nedenleriyle, container’lar Alpine veya Debian’ın bir önceki kararlı (stable) sürümünden build edilmelidir.
- Ayrıca her servis için bir tane olmak üzere kendi Dockerfile’larınızı yazmanız gerekiyor. Dockerfile’lar, Makefile’ınız tarafından docker-compose.yml içinde çağrılmalıdır
- Bu, projenizin Docker imajlarını kendinizin build (oluşturmak) etmeniz gerektiği anlamına gelir. Hazır Docker imajlarını çekmek ve DockerHub gibi hizmetleri kullanmak yasaktır (Alpine/Debian bu kuraldan hariçtir).



-> hostname ve domain name arasındaki fark nedir ?(önemli)

root password: 1234apo!
user : abdullah passowrd: apoQ77
