
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*
Main testleri kesinlikle arttır
Leaklerede Bak
*/
int main(void)
{
    std::cout << "<<<ShrubberyCreationForm Tests>>>" << std::endl;
    {
        Bureaucrat	            Odin("Odin", 110);
        Intern                  new_eleman;
        ShrubberyCreationForm   shru(Odin);

        try {
            new_eleman.makeForm("Shrubbery Creation", Odin);
            shru.beSigned(Odin);
            shru.execute(Odin);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "<<<PresidentialPardonForm Tests>>>" << std::endl;
    {
        Bureaucrat	            Thor("Odin", 25);
        Intern                  new_eleman;
        PresidentialPardonForm  pres(Thor);

        try {
            new_eleman.makeForm("Presidential Pardon", Thor);
            pres.beSigned(Thor);
            pres.execute(Thor);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    return (0);
}
