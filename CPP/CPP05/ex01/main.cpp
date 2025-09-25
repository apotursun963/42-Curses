
#include "Bureaucrat.hpp"
#include "Form.hpp"


/*
Main testleri kesinlikle arttır
*/
int main(void)
{
	std::cout << "<<<Form1 Tests>>>\n";
	{
		Form 		form1("iddianame", 74, 55);

		try {
			Bureaucrat	Hasan("Hasan", 73);
			std::cout << Hasan << std::endl;
			form1.beSigned(Hasan);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << form1 << std::endl;
	}

	std::cout << "<<<Form2 Tests>>>\n";
	{
		Form 		form2("iddianame", 74, 55);

		try {
			Bureaucrat	Huseyn("Huseyn", 76);
			std::cout << Huseyn << std::endl;
			form2.beSigned(Huseyn);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << form2 << std::endl;
	}
    return (0);
}





/* EX01
Her Büroktartlara form verilyor ve bu Bürokratlar bu formları imzalayabilecek,
ama belirli kurallara göre.

Form için verilen gradeToSign ve gradeToExecute değerleri de Bureaucrat ile 
aynı kurallara bağlı (1 en yüksek, 150 en düşük).
Eğer değerler sınırların dışında olursa:
Çok yüksek olursa → Form::GradeTooHighException
Çok düşük olursa → Form::GradeTooLowException fırlatılacak.
*/


