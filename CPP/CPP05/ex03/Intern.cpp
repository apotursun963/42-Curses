
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return (*this);
}

const char *Intern::WrongNameException::what() const throw() {
    return ("Form Name Is Not True");
}

// !!DİKKAT makeForm ikinci parametre string olması gerekiyor diyor. araştır
AForm *Intern::makeForm(std::string form_name, Bureaucrat &target) const {
	AForm *form = NULL;
	AForm *(Intern::*funcPtr[3])(Bureaucrat &target) const = {
        &Intern::makePresidential, 
        &Intern::makeRobotomy, 
        &Intern::makeShrubbery
    };
	std::string forms[3] = {
        "Presidential Pardon", 
        "Robotmy Request",
        "Shrubbery Creation"
    };
    for (int i=0; i < 3; i++) {
        if (forms[i] == form_name) {
            form = (this->*funcPtr[i])(target);
            std::cout << "Intern creates " << form_name << std::endl;
            return (form);
        }
    }
	std::cout << "Intern can't create " << form_name << std::endl;
	throw Intern::WrongNameException();
	return (NULL);
}

// 3'ünü kısaltabilirisin 
AForm *Intern::makePresidential(Bureaucrat & target) const {
	AForm *form = new PresidentialPardonForm(target);
	return (form);
}

AForm *Intern::makeRobotomy(Bureaucrat & target) const {
	AForm *form = new RobotomyRequestForm(target);
	return (form);
}

AForm *Intern::makeShrubbery(Bureaucrat & target) const {
	AForm *form = new ShrubberyCreationForm(target);
	return (form);
}
