#include "PresidentialPardonForm.hpp"

// sign 25, exec 5
PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm::AForm("iddianame", 25, 5), target(target) {

    }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
    : AForm::AForm(other), target(other.target) {
        *this = other;
    }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &right) {
	out << "Form name: " << right.getName() << std::endl;
    if (right.getSigned())
        out << "Signed: True";
    else
        out << "Signed: False";
    return (out);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    executor.executeForm(*this);
    if (this->getSigned() == true)
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        std::cout << this->getName() << " is not signed can't execute" << std::endl;
}
