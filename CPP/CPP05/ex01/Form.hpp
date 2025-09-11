

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Form {
private:
    std::string const name;                 // Formun adı
    bool              is_signed;            // Form imzalanmış mı? (Başlangıçta false).
    int const         gradeToSign;                  // İmzalamak için gereken minimum seviye (derece)
    int const         gradeToExecute;               // Çalıştırmak için gereken minimum seviye (derece)

public:
    // ORTHODOX
    

    void beSigned(Bureaucrat &b);

    std::string getName(void);
    bool        getSigned(void);
    int         getSignGrade(void);
    int         getExecuteGrade(void);


    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &right);