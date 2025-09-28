
#include "AForm.hpp"

AForm::AForm() : name("tursun"), is_signed(false), gradeToSign(150), gradeToExecute(150)  {}

AForm::AForm(std::string name, int Grade_To_Sign, int Grade_To_Execute)
    : name(name), is_signed(false), gradeToSign(Grade_To_Sign), gradeToExecute(Grade_To_Execute) {}

AForm::AForm(const AForm &other) 
    : name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}


AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->is_signed = other.is_signed;
    return (*this);
}

AForm::~AForm() {}


std::string AForm::getName(void) const { return (this->name); }
bool        AForm::getSigned(void) const { return (this->is_signed); }
int         AForm::getSignGrade(void) const { return (this->gradeToSign); }
int         AForm::getExecuteGrade(void) const { return (this->gradeToExecute); }


void AForm::beSigned(Bureaucrat &b) {
    if (this->is_signed) {
        std::cout << this->name << " is already signed" << std::endl;
        return ;
    }
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    else {
        this->is_signed = true;
        b.signForm(this->name, this->is_signed);
    }
}

std::ostream &operator<<(std::ostream &out, AForm const &right) {
	out << "AForm name: " << right.getName() << std::endl;
    if (right.getSigned())
        out << "Signed: True";
    else
        out << "Signed: False";
    return (out);
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade is too low to sign.");
}
