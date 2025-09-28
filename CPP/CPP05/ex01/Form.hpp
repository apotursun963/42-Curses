
#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Form {
private:
    std::string const name;
    bool              is_signed;
    int const         gradeToSign;
    int const         gradeToExecute;

public:
    Form();
    Form(std::string name, int Grade_To_Sign, int Grade_To_Execute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    void beSigned(Bureaucrat &b);

    std::string getName(void) const;
    bool        getSigned(void) const;
    int         getSignGrade(void) const;
    int         getExecuteGrade(void) const;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Form &right);
