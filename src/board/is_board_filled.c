/*
** EPITECH PROJECT, 2026
** is_board_filled
** File description:
** functions to check if a column or the board is filled
*/

#include "config.h"

int is_column_filled(settings_t *settings, int column)
{
    cell_t **board = settings->board;
    int upper_cell = 0;

    if (board[upper_cell][column - 1].taken == 0)
        return 0;
    return 1;
}

int is_board_filled(settings_t *settings)
{
    int width = settings->width;

    for (int column = 1; column <= width; column++) {
        if (is_column_filled(settings, column) == 0)
            return 0;
    }
    return 1;
}
