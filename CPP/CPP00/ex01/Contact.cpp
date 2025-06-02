
#include "Contact.hpp"

// Her üye fonksiyon, sınıfın o anki örneğini işaret eden gizli bir işaretçi (this) alır.
// this olmadan da çalışır, ama örnek bazen gerekli olur
void Contact::set(std::string& f, std::string& l, std::string& n, std::string& p, std::string& s)
{
     this->firstName = f; this->lastName = l;
     this->nickName = n; this->phoneNumber = p; this->secret = s;
}

std::string Contact::getFirstName() { return this->firstName; }
std::string Contact::getLastName()  { return this->lastName; }
std::string Contact::getNickName()  { return this->nickName; }
std::string Contact::getPhone()     { return this->phoneNumber; }
std::string Contact::getSecret()    { return this->secret; }
