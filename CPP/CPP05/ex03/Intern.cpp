
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

AForm *Intern::makeForm(std::string form_name, std::string target) const {
    // AForm *form = NULL;
	AForm *(Intern::*funcPtr[3])(std::string target) const = {
        &Intern::makePresidential,
        &Intern::makeRobotomy,
        &Intern::makeShrubbery
    };
	std::string forms[3] = {
        "Presidential Pardon", 
        "Robotomy Request",
        "Shrubbery Creation"
    };
    for (int i=0; i < 3; i++) {
        if (forms[i] == form_name) {
            AForm * form = (this->*funcPtr[i])(target);
            std::cout << "Intern creates " << form_name << std::endl;
            return (form);
        }
    }
	std::cout << "Intern can't create " << form_name << std::endl;
	throw Intern::WrongNameException();
	return (NULL);
}

// 3'ünü kısaltabilirisin 
AForm *Intern::makePresidential(std::string target) const {
	/*
    - heap’te nesne oluşturuyor.
    - Adresi geçici bir pointer değişkenine atamıyorum.
    */
    return (new PresidentialPardonForm(target)); 
}

AForm *Intern::makeRobotomy(std::string target) const {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string target) const {
	return (new ShrubberyCreationForm(target));
}
