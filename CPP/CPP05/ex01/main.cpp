

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
Main testleri kesinlikle arttır
*/
int main(void)
{
	Form 		form("iddianame", 74);
	Bureaucrat	*Odin = NULL;

	
	try {
		Odin = new Bureaucrat("Odin", 55);
        form.beSigned(*Odin);
    }
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << *Odin << std::endl;
	std::cout << form << std::endl;
	delete Odin;
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

