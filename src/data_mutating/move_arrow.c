/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** moves the arrow bellow the board
*/

#include "config.h"

int move_arrow(int key, cell_t **board, int *arrow_pos, int width)
{
    int move = 0;
    int i_pos = *arrow_pos - 1;

    if (key == KEY_LEFT)
        move = -1;
    else
        move = 1;
    i_pos += move;
    for (; i_pos >= 0 && i_pos < width; i_pos += move) {
        if (board[0][i_pos].taken == 0) {
            *arrow_pos = i_pos + 1;
            return KEY_OTHER_EVENT;
        }
    }
    return KEY_NOTHING_PRESSED;
}
