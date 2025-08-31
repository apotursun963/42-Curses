
#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->CatBrain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    delete this->CatBrain;      // yeni nesnede CatBrain zaten default olarak oluşturulmuş olabilir, önce eskiyi siliyoruz.
	std::cout << "Cat Copy constructor called" << std::endl;
    // other nesnesinin Brain’ini yeni bir Brain nesnesi olarak kopyalıyoruz. Bu sayede deep copy yapılmış oluyor.
    this->CatBrain = new Brain(*other.CatBrain);
    /*
    Eğer bunu yapmasaydık, CatBrain pointer’ı aynı heap adresini 
    gösterirdi → shallow copy → iki nesne de aynı Brain’i paylaşır → biri değiştirirse diğeri de değişir.
    */
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        delete this->CatBrain;
        this->CatBrain = new Brain(*other.CatBrain);
    }
    return (*this);
}

Cat::~Cat() {
    delete this->CatBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwww" << std::endl;
}
