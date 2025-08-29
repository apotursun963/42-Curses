



# Kalıtım Nedir ?
- Kalıtım, bir sınıfın başka bir sınıfın özelliklerini (değişkenler, fonksiyonlar) miras almasıdır.
- Böylece ortak özellikleri tekrar tekrar yazmak yerine kod tekrarını önler ve sınıflar arasında ilişki kurar
Özet: Bir sınıfın başka bir sınıftan türemesidir.

Kalıtım Türleri:
- public inheritance
    * Taban sınıfın public üyeleri → alt sınıfta da public olur.
    * class Alt : public Taban { ... };
- protected inheritance
    * Taban sınıfın public üyeleri → alt sınıfta protected olur. Daha kısıtlı bir erişim sağlar
    * class Alt : protected Taban { ... };
- private inheritance
    * Taban sınıfın public üyeleri → alt sınıfta private olur. Dışarıdan erişilemez.
    * class Alt : private Taban { ... };


## Tekli Kalıtım (Single Inheritance)
- Bir sınıf tek bir sınıftan türetilir.
- class B : public A { };

## Çoklu Kalıtım (Multiple Inheritance)
- Bir sınıf birden fazla sınıftan türetilir.
- Güçlüdür ama aynı sınıftan iki kez türeme sorununu doğurabilir
- class D : public B, public C { };

## Virtual Kullanımı (Sanal Kalıtım)
- Çoklu kalıtımda aynı üst sınıfın birden fazla kopyalanmasını engeller
- virtual ile tanımlandığında, ortak taban sınıftan tek bir kopya tutulur.



## C++ class flagleri
- -Wshadow and -Wno-shadow 


Constructor ve Destructor Çalışma Sırası
Bir alt sınıf nesnesi oluşturulunca:
- Önce üst sınıfın constructor’u çalışır.
- Sonra alt sınıfın constructor’u çalışır.

Nesne silinince:
- Önce alt sınıfın destructor’u,
- Sonra üst sınıfın destructor’u çalışır.


