/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** adds the needed token into the deepest available row
*/

#include <stdlib.h>

#include "config.h"

int add_token_in_col(settings_t *set, int key, int *arrow_pos, int player_turn)
{
    cell_t **board = set->board;
    int column = key - '0' - 1;
    int row = set->height - 1;

    if (key == '\n')
        column = *arrow_pos - 1;
    while (row >= 0) {
        if ((board[row][column]).taken == 0) {
            board[row][column].taken = player_turn;
            *arrow_pos = column + 1;
            set->last_played[0] = row + 1;
            set->last_played[1] = column + 1;
            return KEY_PLAYED_EVENT;
        }
        row--;
    }
    return KEY_NOTHING_PRESSED;
}
