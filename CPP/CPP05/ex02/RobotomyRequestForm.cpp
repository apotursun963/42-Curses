
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm::AForm("iddianame", 72, 45), target(target) {

    }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm::AForm(other), target(other.target) {
        *this = other;
    }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &right) {
	out << "Form name: " << right.getName() << std::endl;
    if (right.getSigned())
        out << "Signed: True";
    else
        out << "Signed: False";
    return (out);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    executor.executeForm(*this);
    if (this->getSigned() == true) {
        std::cout << "Zzzzz...\nZzzzz...\nZzzzz..." << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << this->target << " has been robotomized\n";
        else
            std::cout << this->target << " was not robotomized\n";
    }
}
