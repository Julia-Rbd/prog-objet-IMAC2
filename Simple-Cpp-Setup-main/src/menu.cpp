#include "menu.hpp"
#include "Hangman.hpp"
#include "guess_the_number.hpp"
#include "get_input_from_user.hpp"
#include <iostream>
#include <functional>
#include <vector>

struct Game {
    std::string name;
    std::function<void()> play;
};

//list of games
std::vector<Game> games = {
    {"Hangman", &play_hangman},
    {"Guess the number", &play_guess_the_number},
};

void show_the_list_of_commands(std::vector<Game> games){
    std::cout << "What do you want to do ?" << std::endl;
    for(size_t i=0 ; i<games.size() ; i++){
        std::cout << i << " : " << games[i].name << "\n"; 
    }
    std::cout << "q : Quit" << std::endl;
}

void show_menu(){
    bool quit = false;
    while (!quit) {
        show_the_list_of_commands(games);
        const auto command = get_input_from_user();

        if(command == 'q'){
            quit = true;
        }
        /*if(std::find(games.begin(), games.end(), command) != games.end()){
            games[command].play;
        }
        else{
            std::cout << "This command is not valid !" << std::endl;
        }*/
    }
}
