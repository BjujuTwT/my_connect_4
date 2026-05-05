/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Returns the highest row filled in a given column
*/

#include "config.h"

int get_highest_played(settings_t *settings, int col)
{
    int height = settings->height;
    cell_t **board = settings->board;

    if (col < 0 || col > settings->width)
        return -1;
    for (int row = height - 1; row >= 0; row--) {
        if (board[row][col - 1].taken == 0)
            return row + 1;
    }
    return -1;
}
