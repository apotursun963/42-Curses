
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm::AForm("iddianame", 145, 137), target(target) {
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::string file_name =  this->target + "_shrubbery";
    std::ofstream output_file(file_name.c_str());

    executor.executeForm(*this);
    if (this->getSigned() == true) {
        output_file << "      &&& &&  & &&\n";
        output_file << "   && &\\/&\\|& ()|/ @, &&\n";
        output_file << "   &\\/(/&/&||/& /_/)_&/_&\n";
        output_file << " &() &\\/&|()|/&\\/ '%\" & ()\n";
        output_file << "&_\\/&_/|&/&||/& /_/)_&/_&\n";
        output_file << "&&   && & &| &| /& & % ()&\n";
        output_file << "   ()&_---()&\\&\\|&&-&&--%\n";
        output_file << "           &&     \\|||\n";
        output_file << "           |||     |||\n";
        output_file << "           |||     |||\n";
        output_file << "           |||     |||\n";
        output_file << "       ____|||____ |||\n";
    }
    output_file.close();
}
