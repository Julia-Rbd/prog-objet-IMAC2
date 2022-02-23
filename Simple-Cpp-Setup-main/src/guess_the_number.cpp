#include "guess_the_number.hpp"
#include <iostream>
#include <random>

int rand(int min, int max) {
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

void play_guess_the_number(){
    const int number_picked = rand(0,100);
    int number_chosen;

    std::cout << " I picked a number between 0 and 100" << std::endl;
    std::cin >> number_chosen;

    while(number_chosen != number_picked){
        if(number_chosen < number_picked){
            std::cout << "Greater \n";
            std::cin >> number_chosen;
        }
        else if (number_chosen > number_picked) {
            std::cout << "Smaller \n";
            std::cin >> number_chosen;
        }
    }

    std::cout << "Congrats, you won !";
}