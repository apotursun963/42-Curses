
#include "Bureaucrat.hpp"


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
        throw (Bureaucrat::GradeTooHighException());        // throw bir nesne fırlatıyor
                    // Bu durumda program anında try bloğundan çıkar, ve uygun catch bloğu aramaya başlar.
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

/*
Bu kod bir operator overloading örneği. 
Yani << (insertion operator) özel olarak tanımlanıyor ki, bir Bureaucrat nesnesini
std::cout veya başka bir std::ostream ile kolayca ekrana yazdırabilesin.
*/
std::ostream &operator<<(std::ostream &out, Bureaucrat const &right) {
	out << right.getName() << ", bureaucrat grade " << right.getGrade();
	return (out);
}
