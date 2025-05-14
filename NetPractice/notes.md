1. **Routing Table (Yönlendirme Tablosu)**, bir yönlendirici veya bilgisayarın **gelen paketin** hangi **hedef**e hangi **arayüz**e ve \*\*geçit (gateway)\*\*e gönderileceğini belirlemek için tuttuğu tablodur.

Kısaca içeriği ve işlevi:

* **Hedef Ağ (Destination)**: Paket gitmek istediği IP ağı veya ağırlıklı IP adresi (örn. `192.168.1.0/24` veya `0.0.0.0/0`).
* **Ağ Maskesi (Netmask/Prefix)**: Hedef ağın büyüklüğünü tanımlar (ör. `/24`).
* **Geçit (Gateway)**: Paket bu ağ dışındaysa yönlendiricinin IP’si (örn. `192.168.1.1`).
* **Arayüz (Interface)**: Paketin çıkacağı fiziksel veya sanal ağ arayüzü (örn. `eth0`, `wlan0`).
* **Ölçüt (Metric)**: Birden fazla yol varsa “maliyet” değeri; en düşük metrikli yol seçilir.

**Nasıl kullanılır?**

1. Gelen her paket için önce **hedef IP**’nin hangi ağ satırıyla eşleştiği bulunur.
2. En uzun (en spesifik) eşleşmeye sahip satır seçilir.
3. Paket, o satırdaki **gateway** ve **interface** bilgisine göre gönderilir.

Bu sayede cihazınız veya ağınızdaki router’lar, internet ve yerel ağ trafiğini doğru hedeflere yönlendirir.


2. Router'lar Hangi Ağa Bağlı olduklarını Öğrenirler. Yani, Bir yönlendirici (router), her bağlı olduğu ağ arayüzüne (fiziksel veya sanal) bir IP adresi ve alt ağ maskesi atar.


3. Gateway; her bir cihazın (host’un) kendi bulunduğu yerel ağın dışına çıkmak için kullandığı varsayılan çıkış noktasıdır. Yani bir paketin hedefi yerel ağın dışındaysa, o paketi önce gateway’e (router arayüzünün IP’sine) yollar; oradan devam ederek diğer ağlara ulaşır.

4. Router, Ağlar arası veri iletiminden sorumludur.

5. Ağ içi (aynı LAN) veri iletimini yönetir.

6. Access Point (Erişim Noktası), kablosuz (Wi-Fi) cihazların kablolu ağa (LAN) bağlanmasını sağlayan ara birimdir.