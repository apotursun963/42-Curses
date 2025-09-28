
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "<<<ShrubberyCreationForm Tests>>>" << std::endl;
    {
        try {
            Bureaucrat	Huseyn("Huseyn", 136);
            ShrubberyCreationForm aloo("palantir");

            aloo.beSigned(Huseyn);
            aloo.execute(Huseyn);
    
            std::cout << aloo << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "<<<RobotomyRequestForm Tests>>>" << std::endl;
    {
        try {
            Bureaucrat	Sodin("Huseyn", 44);
            RobotomyRequestForm baloo("spider");

            baloo.beSigned(Sodin);
            baloo.execute(Sodin);

            std::cout << baloo << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "<<<PresidentialPardonForm Tests>>>" << std::endl;
    {
        try {
            Bureaucrat	Adin("Huseyn", 3);
            PresidentialPardonForm daloo("tursun");
    
            daloo.beSigned(Adin);
            daloo.execute(Adin);

            std::cout << daloo << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    return (0);
}
