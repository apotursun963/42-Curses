#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();


    AForm *makeForm(std::string form, std::string target) const;

    AForm *makePresidential(std::string target) const;
    AForm *makeRobotomy(std::string target) const;
    AForm *makeShrubbery(std::string target) const;

	class WrongNameException : public std::exception {
        const char *	what() const throw();
	};
};
