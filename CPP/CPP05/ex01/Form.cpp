

#include "Form.hpp"

Form::Form() : name("tursun"), is_signed(false), gradeToSign(150), gradeToExecute(150)  {}

Form::Form(std::string name, int Grade_To_Sign, int Grade_To_Execute) 
    : name(name), is_signed(false), gradeToSign(Grade_To_Sign), gradeToExecute(Grade_To_Execute) {
    if ((Grade_To_Sign > 150) || (Grade_To_Execute > 150))
        throw (Bureaucrat::GradeTooLowException());
    if ((Grade_To_Sign < 1) || (Grade_To_Execute < 1))
        throw (Bureaucrat::GradeTooHighException());
}

Form::Form(const Form &other) 
    : name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}


Form &Form::operator=(const Form &other) {
    if (this != &other)
        this->is_signed = other.is_signed;
    return (*this);
}

Form::~Form() {}


std::string Form::getName(void) const { return (this->name); }
bool        Form::getSigned(void) const { return (this->is_signed); }
int         Form::getSignGrade(void) const { return (this->gradeToSign); }
int         Form::getExecuteGrade(void) const { return (this->gradeToExecute); }


/*
- Eğer bürokratın derecesi formun imzalanması için gereken dereceden yüksek 
ya da eşit ise (unutma: 1 en yüksek derece, yani 1 > 2), formun durumunu signed = true yapacak.
- Eğer bürokratın derecesi çok düşükse (yani yeterince “yüksek” değilse), Form::GradeTooLowException fırlatacak.
- Bürokratın derecesi yeterliyse form imzalanıyo
*/
void Form::beSigned(Bureaucrat &b) {
    if (this->is_signed) {
        std::cout << this->name << " is already signed" << std::endl;
        return ;
    }
    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else {
        this->is_signed = true;
        b.signForm(this->name, this->is_signed);
    }
}

std::ostream &operator<<(std::ostream &out, Form const &right) {
	out << "Form name: " << right.getName() << std::endl;
    if (right.getSigned())
        out << "Signed: True";
    else
        out << "Signed: False";
    return (out);
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade is too low to sign.");
}
