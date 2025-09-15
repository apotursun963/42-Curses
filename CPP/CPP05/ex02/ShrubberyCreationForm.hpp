#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    Bureaucrat &target;

public:
    ShrubberyCreationForm(Bureaucrat &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &right);
