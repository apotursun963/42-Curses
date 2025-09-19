
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return (*this);
}

Intern::~Intern() {}

/*
makeForm() fonksiyonu, intern’in hangi formu üretmesi gerektiğini anlamasını sağlar 
ve uygun AForm türevinden bir nesne oluşturup sana geri verir.
*/
AForm *   Intern::makeForm(std::string form_name, Bureaucrat &target) const {
    AForm *form = NULL;
    std::string forms_arr[] = {"Presidential Pardon", "Robotmy Request", "Shrubbery Creation"};
    AForm *(Intern::*funcptr[3])(Bureaucrat &target) const = {
        &Intern::makePresidential, &Intern::makeRobot, &Intern::makeShrubbery
    };

    for (int i=0; i < 3; i++) {
        if (forms_arr[i] == form_name) {
            form = (this->*funcptr[i])(target);
            std::cout << "Intern creates " << form_name << std::endl;
            return (form);
        }
    }
    std::cout << "Intern can't create " << form_name << std::endl;
    throw Intern::WrongNameException();
    return (NULL);
}

AForm* Intern::makePresidential(Bureaucrat &target) const {
    AForm* form = new PresidentialPardonForm(target);
    return (form);
}

AForm* Intern::makeRobot(Bureaucrat &target) const {
    AForm* form = new RobotomyRequestForm(target);
    return (form);
}

AForm* Intern::makeShrubbery(Bureaucrat &target) const {
    AForm* form = new ShrubberyCreationForm(target);
    return (form);
}


const char * Intern::WrongNameException::what() const throw() {
    return ("Invalid Form Name");
}

