
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	Odin("Odin", 1);
	Bureaucrat	Loki("Loki", 150);

	std::cout << Odin << std::endl;
	std::cout << Loki << std::endl;

	try {							// try bloğuna istisna/hata durumlarını oluşturabilecek kodları yazarız.
        Odin.increment();
    }
	/*
	- catch bloğu, fırlatılan istisnayı yakalar.
	- std::exception &e → fırlatılan istisna std::exception sınıfından türemiş olmalı.
	- Senin GradeTooHighException ve GradeTooLowException sınıfları std::exception’dan türediği için bu catch onları da yakalar.
	- Yakalanan istisna nesnesinin mesajını almak için what() kullanılır:
	*/
	catch (std::exception &e) {	
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return (0);
}



/* EX00
Bir bürokratı (Bureaucrat) modelleyen basit bir sınıf yazmak.
Her bürokratın değişmez bir adı var.
Her bürokratın derecesi (rütbesi) var (1 en yüksek, 150 en düşük).
Derece sınırlarını korumak için istisnalar (exceptions) kullanılıyor.
Derece yükseltme/düşürme işlemleri yapılabiliyor.
Bürokraat bilgisi ekrana özel formatta yazdırılabiliyor.


Mantık
---
- try bloğu: Potansiyel olarak hata (istisna) fırlatabilecek kodların (örneğin, bürokratlarla ilgili işlemler) çalıştırıldığı yerdir.
Eğer bir hata olursa, kod buradan çıkar ve yakındaki catch bloğuna atlar.
- catch bloğu: Fırlatılan istisnayı yakalar ve işler. Burada std::exception & e parametresi, yakalanan istisnanın detaylarını tutar.

try içindeki kod bir istisna fırlatırsa (örneğin, throw std::runtime_error("Hata oluştu!");), 
bu istisna std::exception sınıfından (veya türevinden) olmalıdır ki yakalansın.
catch bloğu, bu istisnayı yakalar. e üzerinden istisna detaylarına erişebilirsiniz:

e.what(): Hata mesajını döndürür (string olarak).
Örnek: std::cout << "Hata: " << e.what() << std::endl;

Eğer fırlatılan istisna std::exception'dan türememişse (örneğin, basit bir int veya özel bir sınıf), 
bu catch onu yakalayamaz – program çökebilir veya başka bir catch bloğuna gider.

*/
