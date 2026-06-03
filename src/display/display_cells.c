/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** displays each cell based on the cell_t ** struct given
** and player pattern(s)
*/

#include <stdlib.h>

#include "config.h"
#include "my.h"

static void place_token(settings_t *settings,
    int row, int column)
{
    ll_player_info_t *pl_ptr = NULL;
    cell_t cell = (settings->board)[row][column];
    int played_by = cell.taken;
    int pos_x = get_x_from_column(settings, column + 1);
    int pos_y = get_y_from_row(settings, row + 1);

    pl_ptr = get_player_from_id(settings->player_info, played_by);
    display_pattern_coordinates(settings, pos_x, pos_y, pl_ptr);
    return;
}

static void display_cell_row(settings_t *settings, int row, int width)
{
    cell_t *board_row = (settings->board)[row];

    for (int column = 0; column < width; column++) {
        if (board_row[column].taken != 0)
            place_token(settings, row, column);
    }
    return;
}

void display_cells(settings_t *settings)
{
    int width = settings->width;
    int height = settings->height;

    for (int row = 0; row < height; row++)
        display_cell_row(settings, row, width);
    return;
}
