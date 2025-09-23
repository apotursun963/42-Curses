
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


// sign = 72, exec = 45
/*
sign: Formu imzalamak için Bureaucrat’ın grade’i 72 veya daha yüksek olmalı.
exec: Formu çalıştırmak için Bureaucrat’ın grade’i 45 veya daha yüksek olmalı.
*/
RobotomyRequestForm::RobotomyRequestForm(Bureaucrat &target) 
    : AForm::AForm("iddianame", 72, 45), target(target) {

    }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm::AForm(other), target(other.target) {
        *this = other;
    }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &right) {
	out << "Form name: " << right.getName() << std::endl;
    if (right.getSigned())
        out << "Signed: True";
    else
        out << "Signed: False";
    return (out);
}


/*
- Çalıştırıldığında önce matkap sesi / drilling noise gibi bir mesaj basacak.
- Sonra %50 ihtimalle başarılı, %50 ihtimalle başarısız olacak.
    - Başarılıysa: <target> has been robotomized successfully
    - Başarısızsa: <target> robotomy failed
Hata kontrolü
- Form imzalı mı?
- Executor grade yeterli mi?
- Değilse uygun exception fırlatılacak.
kısacası execute : Konsola matkap sesi + %50 başarı/başarısız mesajı basıyor
*/


void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    executor.executeForm(*this);
    if (this->getSigned() == true) {
        std::cout << "Drill Noises\nDrill Noises\nDrill Noises\n";
        srand(time(NULL));  // rastgele sayı üretiyor ve her çalışmada/derlemede rand sayı üretiyor.
        if (rand() % 2 == 0)    // Rastgele sayı üretiliyor (rand() % 2 → 0 veya 1) %50 ihtimalle başarılı veya başarısız mesajı seçiliyor:
            std::cout << this->target << " has been robotomized\n";
        else
            std::cout << this->target << " was not robotomized\n";
    }
}
