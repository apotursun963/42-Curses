#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    int               grade;        // bürokratın derecesi (1 en yüksek, 150 en düşük)
    std::string const name;         // sabit, değiştirilemez isim

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

    void    executeForm(AForm const & form) const;
    void    signForm(std::string name, bool sign);

    // Bu, özel bir hata (istisna) sınıfıdır .
    // what() -> hata yakalandığında geri döneceğine dair mesaj yazılır.
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &right);
