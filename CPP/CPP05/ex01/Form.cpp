


#include "Form.hpp"




std::string Form::getName(void) { return (this->name); }
bool        Form::getSigned(void) { return (this->is_signed); }
int         Form::getSignGrade(void) { return (this->gradeToSign); }
int         Form::getExecuteGrade(void) { return (this->gradeToExecute); }


// Eğer bureaucrat’ın derecesi (grade) yeterli seviyede ise (yeterince büyükse) → isSigned = true
// yok eğer çok düşükse → GradeTooLowException fırlat.
void Form::beSigned(Bureaucrat &b) {
    if (this->is_signed) {
        std::cout << this->name << " is already signed" << std::endl;
        return ;
    }
    // if (b.getGrade() > this->gradeToSign)

}
