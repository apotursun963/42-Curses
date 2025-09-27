
#pragma once

#include <iostream>
#include <string>

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

    // Bu, özel bir hata (istisna) sınıfıdır .
    // what() -> hata yakalandığında geri döneceğine dair mesaj yazılır.
    /*
    - const char* -> dönüş tipi
    - what() -> Fonksiyon ismi (std::exception sınıfında vardı zaten biz onu miras alıp override ediyoruz)
    - const -> const memeber funcs yani sınıftaki üyelerin/özelliklerin durumlarını değiştiremez.
    - throw() -> istisna bildirimi
    */
    class GradeTooHighException : public std::exception {
        const char* what() const throw();       // fonksiyonu prototipi
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &right);
