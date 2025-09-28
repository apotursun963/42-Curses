
#pragma once

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
private:
    std::string const name;
    bool              is_signed;
    int const         gradeToSign;
    int const         gradeToExecute;

public:
    AForm();
    AForm(std::string name, int Grade_To_Sign, int Grade_To_Execute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    virtual void execute(Bureaucrat const &executor) const = 0;
    void beSigned(Bureaucrat &b);

    std::string getName(void) const;
    bool        getSigned(void) const;
    int         getSignGrade(void) const;
    int         getExecuteGrade(void) const;

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const AForm &right);
