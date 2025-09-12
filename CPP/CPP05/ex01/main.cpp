
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	Odin("Odin", 75);
	Bureaucrat	Loki("Loki", 1);
	Form 		form("iddianame", 74);

	std::cout << Odin << std::endl;
	std::cout << Loki << std::endl;

	try {
        form.beSigned(Odin);
    }
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return (0);
}



/* EX01
Her Büroktartlara form verilyor ve bu Bürokratlar bu formları imzalayabilecek, ama belirli kurallara göre.

Form için verilen gradeToSign ve gradeToExecute değerleri de Bureaucrat ile 
aynı kurallara bağlı (1 en yüksek, 150 en düşük).
Eğer değerler sınırların dışında olursa:
Çok yüksek olursa → Form::GradeTooHighException
Çok düşük olursa → Form::GradeTooLowException fırlatılacak.
*/

