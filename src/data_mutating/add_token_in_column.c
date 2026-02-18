/*
** EPITECH PROJECT, 2026
** add_token_in_row
** File description:
** adds the needed token into the deepest available row
*/

#include "config.h"

int add_token_in_col(int key, cell_t **board, int *arrow_pos, int player_turn)
{
    int column = key - '0' - 1;
    int row = 5;

    if (key == '\n')
        column = *arrow_pos - 1;
    while (row >= 0) {
        if ((board[row][column]).taken == 0) {
            board[row][column].taken = player_turn;
            *arrow_pos = column + 1;
            return 2;
        }
        row--;
    }
    return 0;
}
