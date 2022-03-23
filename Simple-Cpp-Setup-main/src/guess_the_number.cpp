#include "guess_the_number.hpp"
#include "rand.hpp"
#include <iostream>


void play_guess_the_number(){
    const int number_picked = random(0,100);
    int number_chosen;

    std::cout << " I picked a number between 0 and 100" << std::endl;
    std::cin >> number_chosen;

    while(number_chosen != number_picked){
        if(number_chosen < number_picked){
            std::cout << "Greater \n";
            std::cin >> number_chosen;
        }
        else {
            std::cout << "Smaller \n";
            std::cin >> number_chosen;
        }
    }

    std::cout << "Congrats, you won !";
}