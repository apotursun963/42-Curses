

# include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie apo(name);       // apo burada değişken ismidir. ve burada constructure çağırılır
    apo.announce();
}
