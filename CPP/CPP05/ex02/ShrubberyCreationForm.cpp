
#include "ShrubberyCreationForm.hpp"

// sign = 145, exec = 137
ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target) 
    : AForm::AForm("Tree", 145, 137), target(target) {

    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm::AForm(other), target(other.target) {
        *this = other;
    }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &right) {
	out << "Form name: " << right.getName() << std::endl;
    if (right.getSigned())
        out << "Signed: True";
    else
        out << "Signed: False";
    return (out);
}

/*
Formu çalıştırmak isteyen Bureaucrat’ın yetkisi yeterli mi kontrol edecek.
- Form imzalanmış mı kontrol edecek.
- Eğer imza yok veya grade yetersiz → uygun exception fırlatacak.
- Eğer her şey doğruysa, concrete class içindeki “gerçek işlemi” yapan fonksiyonu çağıracak.
*/
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::string file_name =  target.getName() + "_shrubbery";
    std::ofstream output_file(file_name.c_str());

    executor.executeForm(*this);
    if (this->getSigned() == true) {
        output_file << "      &&& &&  & &&" << std::endl;
        output_file << "   && &\\/&\\|& ()|/ @, &&" << std::endl;
        output_file << "   &\\/(/&/&||/& /_/)_&/_&" << std::endl;
        output_file << " &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
        output_file << "&_\\/&_/|&/&||/& /_/)_&/_&" << std::endl;
        output_file << "&&   && & &| &| /& & % ()&" << std::endl;
        output_file << "   ()&_---()&\\&\\|&&-&&--%" << std::endl;
        output_file << "           &&     \\|||" << std::endl;
        output_file << "           |||     |||" << std::endl;
        output_file << "           |||     |||" << std::endl;
        output_file << "           |||     |||" << std::endl;
        output_file << "       ____|||____ |||" << std::endl;
    }
    output_file.close();
}

