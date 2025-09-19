
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


/* Leaklere Bak
Main testleri kesinlikle arttır
*/
int main(void)
{
   Bureaucrat	Odin("Odin", 45);
   RobotomyRequestForm baloo(Odin);
   Intern* new_eleman = new Intern();

	try {
      new_eleman->makeForm("Presidential Pardon", Odin);
      baloo.beSigned(Odin);
   }
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
   delete new_eleman;
   return (0);
}


