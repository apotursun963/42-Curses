
#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : grade(other.grade), name(other.name) {}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n) {
    if (g > 150)
        throw (Bureaucrat::GradeTooLowException());
    else if (g < 1)
        throw (Bureaucrat::GradeTooHighException());
    else
        grade = g;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

int         Bureaucrat::getGrade(void) const { return (this->grade); }
std::string Bureaucrat::getName(void) const { return (this->name); }

void Bureaucrat::increment(void) {
    this->grade--;
    if (this->grade < 1)
        throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrement(void) {
    this->grade++;
    if (this->grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too High");
}

void Bureaucrat::signForm(std::string name, bool sign) {
    if (sign)
        std::cout << this->name << " signed " << name << std::endl;
    else
        std::cout << this->name << " couldn’t sign " << name << "because his grade is not suitable" << std::endl; 
}


std::ostream &operator<<(std::ostream &out, Bureaucrat const &right) {
	out << right.getName() << ", bureaucrat grade " << right.getGrade();
	return (out);
}
