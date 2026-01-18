
# Templates
Bir fonksiyonu veya Bir Class'ı yazarken tipi bağımsız hale getirebiliriz.
Yani, Bir fonksiyonu veya class'ı tanımlarken belirli tiplerin yerine genel tipleri kullanmamıza olanak tanıyor. Böylece aynı kodu farklı tiplerle kullanabiliriz. Bu kod tekrarını azaltır.


- Template (Şablon) Tanımlamak için -> template <typename T>
"T" aslında bir değişken gibidir eğer float yapmak istiyorusanız float oluyor
eğer int tanımlamak istiyorsanısz int oluyorlar. Yani T'ler istediğimiz veri tipine 
dönüşyorlar. T türünde parametreler tanımlıyoruz.


Eğer bir template fonksionu tanımlarsak sonrasında ilk olarak "int" değerler sonra 
"float" değerler olarak func çağırırsak derleyicide func şöyle çalışıyor:
ilk önce derleyici (compiler) ilk satır için (int değerler) T'leri (T türünü) integere 
çeviriyor. sonraki satır için (float değerler) T'leri bu sefer floata çeviriyor.
Böylece, template fonksiyonu şekilden şekile giriyor.


Peki nasıl farklı veri tipleri aynı anda çağırabiliriz/işleme sokabiliriz
template <typename T> -> bu tanımlama funcs tek bir veri Türü (T) alıyor/yani tek bir veri türü ile işlem yapıyor
template <typename T, typename C> -> Bu ise iki tür veri tipini alıyor/iki veri türü ile işlem yapıyor


Template Class (Sınıflar)
---
Template sınıflar, birden fazla veri türüyle çalışabilen sınıf şablonlarıdır.
Aynı işlevi farklı türler için tekrar yazmak yerine, tek bir şablon tanımlayarak kodun yeniden kullanılmasını sağlarlar.

Tanım -> template <class T>

