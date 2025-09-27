
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
        AForm *res_form = NULL;
        try {
            Bureaucrat	            Huseyn("Huseyn", 110);
            Intern                  new_eleman;

            res_form = new_eleman.makeForm("Shrubbery Creation", "Bender");
            res_form->beSigned(Huseyn);
            res_form->execute(Huseyn);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        delete res_form;
    }

    std::cout << "<<<PresidentialPardonForm Tests>>>" << std::endl;
    {
        AForm *res_form = NULL;
        try {
            Bureaucrat	            Thor("Huseyn", 25);
            Intern                  new_eleman;

            res_form = new_eleman.makeForm("Presidental Parodon", "Sender");
            res_form->beSigned(Thor);
            res_form->execute(Thor);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        delete res_form;
    }
    return (0);
}
