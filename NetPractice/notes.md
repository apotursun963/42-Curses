2. Router'lar Hangi Ağa Bağlı olduklarını Öğrenirler. Yani, Bir yönlendirici (router), her bağlı olduğu ağ arayüzüne (fiziksel veya sanal) bir IP adresi ve alt ağ maskesi atar.

3. Gateway; her bir cihazın (host’un) kendi bulunduğu yerel ağın dışına çıkmak için kullandığı varsayılan çıkış noktasıdır. Yani bir paketin hedefi yerel ağın dışındaysa, o paketi önce gateway’e (router arayüzünün IP’sine) yollar; oradan devam ederek diğer ağlara ulaşır.

4. Router, Ağlar arası veri iletiminden sorumludur.

5. Ağ içi (aynı LAN) veri iletimini yönetir.

6. Access Point (Erişim Noktası), kablosuz (Wi-Fi) cihazların kablolu ağa (LAN) bağlanmasını sağlayan ara birimdir.


## CIDR Nedir?
CIDR (Classless Inter-Domain Routing), IP adresinin yanında /28, /24 gibi yazılır ve subnet mask’ın kaç bitinin ağ adresi olduğunu belirtir. 
143.32.17.122/28 Bu demektir ki ilk 28 bit ağ adresidir, geriye kalan 4 bit ise hostlar içindir.
