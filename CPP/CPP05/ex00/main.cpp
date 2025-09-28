
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "<<<Hasan Test>>>\n";
	{
		try {
			Bureaucrat	Hasan("Hasan", 75);
			std::cout << Hasan << std::endl;
	
			Hasan.increment();
			std::cout << "Hasan's Current Grade After increment: " << Hasan.getGrade() << std::endl;
    	}
		catch (std::exception &e) {	
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "<<<Huseyn Test>>>\n";
	{
		try {
			Bureaucrat	Huseyn("Huseyn", 150);
			std::cout << Huseyn << std::endl;

			Huseyn.decrement();
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
    return (0);
}
