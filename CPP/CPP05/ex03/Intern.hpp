#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;            // bunlar neden burada tanımlıyorsun mesela
class Bureaucrat;

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(std::string form, Bureaucrat & target) const;

    AForm *makePresidential(Bureaucrat & target) const;
    AForm *makeRobotomy(Bureaucrat & target) const;
    AForm *makeShrubbery(Bureaucrat & target) const;

	class WrongNameException : public std::exception {
        const char *	what() const throw();
	};
};
