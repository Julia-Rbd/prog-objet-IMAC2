#include "Hangman.hpp"
//#include "rand.hpp"
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>


class WordWithMissingLetters {
    public:
        WordWithMissingLetters(std::string word)
            : _word{word}
            , _letters_guessed(word.size(), false)
        {}

        void change_this_letter_as_guessed(char guessed_letter){
                size_t place = _word.find(guessed_letter);
                _letters_guessed[place] = true;
        }

        void show_word_currently_sought(){
            for(int i=0 ; i<_word.size() ; i++){
                if(_letters_guessed[i]){
                    std::cout << _word[i];
                }
                else{
                    std::cout << "_";
                }
            }
            std::cout << "\n";
        }

        bool word_is_found() const{       //vector of booleans
            const bool result = std::all_of(_letters_guessed.begin(), _letters_guessed.end(), [](bool _letter_guessed) {
               return _letter_guessed;
            });
            return result;
        }

        bool this_letter_is_in_the_word(char letter){
            return _word.find(letter) != std::string::npos;
        }

    private:
        std::string _word;
        std::vector<bool> _letters_guessed;
};

bool player_is_alive(int nb_lives){
    return (nb_lives > 0);
}

WordWithMissingLetters choose_a_word_to_guess(){
    std::array<std::string, 5> words = {
        "code",
        "laptop",
        "imac",
        "chocolate",
        "school",
    };

    return words[0];
    //return words[rand2(0, static_cast<int>(words.size()) - 1)];
}

char get_letter(){
    char guessed_letter;
    std::cin >> guessed_letter;
    return guessed_letter;
}

void show_number_of_lives(int nb_lives){
    if(nb_lives > 1){
        std::cout << "You have " << nb_lives << " lives. \n";
    }
    else if (nb_lives == 1){
        std::cout << "You have only one life left !! \n";
    }
}

void play_hangman(){
    int nb_lives = 8;
    WordWithMissingLetters word_to_guess = choose_a_word_to_guess();

    while(player_is_alive(nb_lives) && !word_to_guess.word_is_found()){

        show_number_of_lives(nb_lives);
        word_to_guess.show_word_currently_sought();
        char guessed_letter = get_letter();

        //the letter is in the word
        if(word_to_guess.this_letter_is_in_the_word(guessed_letter)){
            std::cout << "Correct ! \n";
            word_to_guess.change_this_letter_as_guessed(guessed_letter);
            word_to_guess.show_word_currently_sought();
            show_number_of_lives(nb_lives);
        }

        //the letter is not in the word
        else{
            std::cout << "The letter is not in the word. \n";
            word_to_guess.show_word_currently_sought();
            nb_lives --;
            show_number_of_lives(nb_lives);
        }

    }

    if(word_to_guess.word_is_found()){
        std::cout << "Congrats, you won !" << std::endl;
    }
    else{
        std::cout << "You lose..." << std::endl;
    }
}
