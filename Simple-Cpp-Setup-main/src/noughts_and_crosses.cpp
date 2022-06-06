#include "noughts_and_crosses.hpp"
#include <p6/p6.h>


const float square_size = 1.f / 3.f;

std::array<std::array<squares, 3>, 3> board;


void draw_nought(p6::Context& ctx, std::array<std::array<squares, 3>, 3>& board, int i, int j){
    ctx.stroke = {1, 1, 1, 1};
    ctx.fill = {0.f, 0.f, 0.f, 0.f};
    ctx.stroke_weight = 0.02f;
    ctx.circle(p6::Center{board[i][j].x, board[i][j].y}, p6::Radius{square_size - 0.1f});
}

void draw_cross(p6::Context& ctx, std::array<std::array<squares, 3>, 3>& board, int i, int j){
    ctx.stroke = {1, 1, 1, 1};
    ctx.fill = {0.f, 0.f, 0.f, 0.f};
    ctx.stroke_weight = 0.01f;
    ctx.line(   glm::vec2(board[i][j].x - square_size + 0.1f, board[i][j].y + square_size - 0.1f),
                glm::vec2(board[i][j].x + square_size - 0.1f, board[i][j].y - square_size + 0.1f));
    ctx.line(   glm::vec2(board[i][j].x - square_size + 0.1f, board[i][j].y - square_size + 0.1f),
                glm::vec2(board[i][j].x + square_size - 0.1f, board[i][j].y + square_size - 0.1f));
}

void draw_board(p6::Context& ctx, std::array<std::array<squares, 3>, 3>& board){
    ctx.stroke = {1, 1, 1, 1};
    ctx.stroke_weight = 0.01f;

    //draw the grid
    ctx.line(glm::vec2{-1.f, -0.333f}, glm::vec2{1.f, -0.333f});
    ctx.line(glm::vec2{-1.f, 0.333f}, glm::vec2{1.f, 0.333f});
    ctx.line(glm::vec2{-0.333f, -1.f}, glm::vec2{-0.333f, 1.f});
    ctx.line(glm::vec2{0.333f, -1.f}, glm::vec2{0.333f, 1.f});

    //draw the X and O
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (board[i][j].insideLetter == 'O') {
                draw_nought(ctx, board, i, j);
            }
            else if (board[i][j].insideLetter == 'X') {
                draw_cross(ctx, board, i, j);
            }
        }
    }
}

void fill_the_board(bool& first_player_plays, int line, int column, std::array<std::array<squares, 3>, 3>& board){
    if (board[line][column].insideLetter == ' ') {
        if (first_player_plays) {
            board[line][column].insideLetter = 'X';
        }
        else {
            board[line][column].insideLetter = 'O';
        }
        first_player_plays = !first_player_plays;       //change current player
    }
}

bool the_game_is_over(std::array<std::array<squares, 3>, 3>& board){        //a player has won

    for (int i = 0 ; i < 3 ; i++) {

        // the player wins on a line
        if (board[i][0].insideLetter != ' ' || board[i][1].insideLetter != ' ' || board[i][2].insideLetter != ' ') {
            if (board[i][0].insideLetter == board[i][1].insideLetter && board[i][1].insideLetter == board[i][2].insideLetter) {
                return true;
            }
        }

        // the player wins on a column
        if (board[0][i].insideLetter != ' ' || board[1][i].insideLetter != ' ' || board[2][i].insideLetter != ' ') {
            if (board[0][i].insideLetter == board[1][i].insideLetter && board[1][i].insideLetter == board[2][i].insideLetter) {
                return true;
            }
        }
    }

    // the player wins on a diagonal
    if (board[1][1].insideLetter != ' ') {
        if ((board[0][0].insideLetter == board[1][1].insideLetter && board[1][1].insideLetter == board[2][2].insideLetter) || (board[0][2].insideLetter == board[1][1].insideLetter && board[1][1].insideLetter == board[2][0].insideLetter)) {
            return true;
        }
    }
    
    int taken_places = 0;               //number of squares with an O or an X inside
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (board[i][j].insideLetter != ' ') {
                taken_places++;
            }
        }
    }
    if(taken_places == 9){      // the board is full, we consider that the first player has won
        return true;
    }

    return false;
}


void play_noughts_and_crosses(){

    auto ctx = p6::Context{{800,800,"Noughts and Crosses"}};     // Create a context with a window

    bool first_player_plays = true;

    std::array<std::array<squares, 3>, 3> board;

    float y = 1 - square_size;
    float x = -1 + square_size;
    for (size_t i = 0 ; i < 3 ; i++) {
        for (size_t j = 0; j < 3; j++) {
            board[i][j] = {x, y, ' '};
            x += 2 * square_size;
        }
        x = -1 + square_size;
        y -= 2 * square_size;
    }

    ctx.update = [&]() {
        ctx.background({.1f, 0.25f, 0.35f});
        ctx.fill = {0.f, 0.f, 0.f, 0.f};

        draw_board(ctx, board);

        // Check if there is a winner
        if (the_game_is_over(board)) {

            ctx.stop();

            std::string winner_symbol;
            if(first_player_plays){
                winner_symbol = " 'O' ";
            }
            else{
                winner_symbol = " 'X' ";
            }
            std::cout << "Player who played the " << winner_symbol << " won !";
        }
    };

    ctx.mouse_pressed = [&](p6::MouseButton event) {

        int column_of_the_square_clicked = 1;
        int line_of_the_square_clicked = 1;

        // show which colomn
        if (ctx.mouse()[0] <= -square_size) {
            column_of_the_square_clicked = 0;
        }
        else if (ctx.mouse()[0] >= square_size) {
            column_of_the_square_clicked = 2;
        }

        // show which line
        if (ctx.mouse()[1] >= square_size) {
            line_of_the_square_clicked = 0;
        }
        else if (ctx.mouse()[1] <= -square_size) {
            line_of_the_square_clicked = 2;
        }

        fill_the_board(first_player_plays, line_of_the_square_clicked, column_of_the_square_clicked, board); //fill the board depending on your clickss
    };

    ctx.start();                            //start p6 application
}
