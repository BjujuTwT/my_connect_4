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
    int *props = settings->proportions;
    int x_mid = (props[0] / 2) + 1;
    int pos_x = (2 * x_mid * (col - 1)) + 1 + props[2];

    return pos_x;
}

int get_y_from_row(settings_t *settings, int row)
{
    int cell_height = (settings->proportions)[1];
    int y_mid = (cell_height / 2) + 1;
    int pos_y = (2 * y_mid * (row - 1)) + 1;

    return pos_y;
}
