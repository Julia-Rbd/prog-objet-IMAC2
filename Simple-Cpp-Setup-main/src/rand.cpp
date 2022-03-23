#include "rand.hpp"

int random(int min, int max) {       //rand2() because rand() is considered as a mistake by VSCode
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}
