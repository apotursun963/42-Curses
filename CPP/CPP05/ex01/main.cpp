
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "<<<Form1 Tests>>>\n";
	{		
		try {
			Form form1("iddianame", 74, 55);
			Bureaucrat	Hasan("Hasan", 73);

			std::cout << Hasan << std::endl;
			form1.beSigned(Hasan);

			std::cout << form1 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "<<<Form2 Tests>>>\n";
	{
		
		try {
			Form form2("iddianame", 74, 55);
			Bureaucrat	Huseyn("Huseyn", 76);

			std::cout << Huseyn << std::endl;
			form2.beSigned(Huseyn);

			std::cout << form2 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
    return (0);
}
