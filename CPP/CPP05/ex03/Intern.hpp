#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    // dönüş tipi (AForm) yeni oluşturulmuş form nesnesi
    AForm* makeForm(std::string form, Bureaucrat &target) const;   

    // 3'ünü privateda yapabilrisin
    AForm* makePresidential(Bureaucrat &target) const;
    AForm* makeRobot(Bureaucrat &target) const;
    AForm* makeShrubbery(Bureaucrat &target) const;

    class WrongNameException : public std::exception {
        const char* what() const throw();
    };
};
