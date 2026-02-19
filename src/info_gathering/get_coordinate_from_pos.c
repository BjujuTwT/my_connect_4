/*
** EPITECH PROJECT, 2026
** get_coordinate_from_pos.c
** File description:
** both functions that gets the coordinates on screen from
** positions on the board
** They will send specifically the coordinates of the top left character
** of the cell
*/

#include "config.h"

int get_x_from_column(settings_t *settings, int col)
{
    int cell_width = (settings->proportions)[0];
    int offset = (settings->proportions)[2];
    int pos_x = (col - 1) * (cell_width + 1) + 1 + offset;

    return pos_x;
}

int get_y_from_row(settings_t *settings, int row)
{
    int cell_height = (settings->proportions)[1];
    int pos_y = (row - 1) * (cell_height + 1) + 1;

    return pos_y;
}
