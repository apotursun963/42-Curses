#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    Bureaucrat &target;

public:
    RobotomyRequestForm(Bureaucrat &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &right);
