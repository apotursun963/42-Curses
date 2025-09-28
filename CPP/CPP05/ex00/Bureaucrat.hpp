
#pragma once

#include <iostream>
#include <string>

class Bureaucrat {
private:
    int               grade;
    std::string const name;

public:
    Bureaucrat();
    Bureaucrat(std::string n, int g);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    int         getGrade(void) const;
    std::string getName(void) const;

    void    increment(void);
    void    decrement(void);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &right);
