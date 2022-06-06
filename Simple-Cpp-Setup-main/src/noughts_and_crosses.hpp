#include <p6/p6.h>
#include <cstdlib>
#include <iostream>
#include <vector>

struct squares {
    float x;
    float y;
    char  insideLetter;
};

void draw_nought(p6::Context& ctx, std::array<std::array<squares, 3>, 3>& board, int i, int j);
void draw_cross(p6::Context& ctx, std::array<std::array<squares, 3>, 3>& board, int i, int j);
void draw_board(p6::Context& ctx, std::array<std::array<squares, 3>, 3>& board);
void fill_the_board(bool& first_player_plays, int line, int column, std::array<std::array<squares, 3>, 3>& board);
bool the_game_is_over(std::array<std::array<squares, 3>, 3>& gameboard_squares);
void play_noughts_and_crosses();
