#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &right);
