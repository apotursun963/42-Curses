
#include "Brain.hpp"

Brain::Brain() { 
    std::cout << "Brain Default constructor called" << std::endl;
    SelectRandIdeas();
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain Copy constructor called" << std::endl;
    for (int i=0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i=0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::fill_to_ideas(const std::string arr[]) {
    for (int i=0; i < 100; i++)
        this->ideas[i] = arr[i];        // yada random_ideas[rand() % 10];
}

void Brain::SelectRandIdeas(void) {
    std::string rndm_ids[100] = {
    "Where am I?",
    "Let's play!",
    "I wanna run",
    "I want a friend!",
    "Dreaming of chasing squirrels",
    "Wondering when my human will be back",
    "Planning my next nap",
    "Contemplating the meaning of life (and treats)",
    "Pondering the mysteries of the vacuum cleaner",
    "Plotting to steal a sock",
    "Fantasizing about a world where treats fall from the sky",
    "Calculating the perfect time to wake up my human",
    "Daydreaming about chasing my tail",
    "Considering a career as a professional beggar",
    "Planning a midnight zoomies session",
    "Wondering if I'm a good boy/girl",
    "Fantasizing about the forbidden pleasures of the garbage can",
    "Contemplating the existential crisis of the red dot",
    "Plotting the ultimate escape from the bath",
    "Should I bark at the mailman again?",
    "Thinking about digging a new hole in the yard",
    "Trying to remember where I hid my bone",
    "Wondering why cats act so strange",
    "Planning to chase my shadow later",
    "Debating whether to nap on the couch or the bed",
    "Dreaming of endless belly rubs",
    "Imagining a park with infinite trees",
    "Waiting for someone to drop food",
    "Staring at the wall for no reason",
    "Wondering if I can catch that fly",
    "Thinking about stealing food from the table",
    "Should I bark at nothing again?",
    "Pondering the life of a squirrel",
    "Imagining a field full of tennis balls",
    "Trying to look cute to get treats",
    "Wondering why humans stare at screens",
    "Dreaming of chasing butterflies",
    "Planning my next sneak attack",
    "Contemplating the sound of the fridge door",
    "Hoping for a car ride soon",
    "Imagining running faster than the wind",
    "Thinking about splashing in puddles",
    "Hoping for a belly rub marathon",
    "Wondering if shoes are chew toys",
    "Plotting to guard the house from leaves",
    "Thinking about rolling in the grass",
    "Dreaming of chasing birds",
    "Wishing I could talk to my human",
    "Wondering why baths exist",
    "Debating whether to chew the couch",
    "Hoping to find a secret snack",
    "Dreaming of running with the pack",
    "Wondering what the cat is plotting",
    "Planning a surprise jump on the bed",
    "Imagining the taste of bacon",
    "Waiting for the doorbell to ring",
    "Dreaming about a treat mountain",
    "Wondering if I can open the fridge",
    "Thinking about cuddling all day",
    "Planning to dig under the fence",
    "Pondering the mysteries of thunder",
    "Hoping to find another sock",
    "Dreaming of swimming in a lake",
    "Wishing for endless squeaky toys",
    "Wondering if the postman fears me",
    "Thinking about taking over the couch",
    "Contemplating if I’m the fastest dog",
    "Hoping for a long walk",
    "Imagining being a superhero dog",
    "Planning to sneak into the bed tonight",
    "Dreaming of bones bigger than me",
    "Wishing treats grew on trees",
    "Thinking about the next belly rub",
    "Wondering what happens outside the window",
    "Imagining a world without leashes",
    "Hoping to play fetch forever",
    "Planning to guard my toy stash",
    "Dreaming of chasing waves",
    "Thinking about stealing slippers",
    "Wondering if cats secretly like me",
    "Hoping for an adventure in the park",
    "Dreaming about snowball fights",
    "Planning to hide in the blanket fort",
    "Imagining chasing stars",
    "Wondering why humans wear clothes",
    "Hoping to discover new smells",
    "Dreaming about sleeping on a cloud",
    "Thinking about barking at the moon",
    "Planning a tug-of-war victory",
    "Imagining a river of treats",
    "Wondering if I could drive a car",
    "Dreaming of flying with birds",
    "Planning my ultimate zoomies",
    "Thinking about chasing raindrops",
    "Wondering if I’m the best boy",
    "Hoping to meet another puppy",
    "Imagining a world of chew toys",
    "Dreaming about sleeping in the sun"
    };
    fill_to_ideas(rndm_ids);
}
