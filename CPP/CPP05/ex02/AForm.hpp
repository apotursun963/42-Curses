
#pragma once

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>


class Bureaucrat;       // Forward declaration -> nedir öğren

class AForm {
private:
    std::string const name;                         // AFormun adı
    bool              is_signed;                    // AForm imzalanmış mı? (Başlangıçta false).
    int const         gradeToSign;                  // İmzalamak için gereken seviye (derece)
    int const         gradeToExecute;               // Çalıştırmak için gereken seviye (derece)

public:
    AForm();
    AForm(std::string name, int Grade_To_Sign, int Grade_To_Execute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();       // Bunu virtual yap

    // sanal funcs: Bu fonksiyon sanaldır, yani polymorphism (çok biçimlilik) için kullanılacak.
    virtual void execute(Bureaucrat const &executor) const = 0; // pure virtual: prototoipi var gövdesi yok alt sınıflarda implement edilmesi gerekiyor
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
