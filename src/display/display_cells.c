/*
** EPITECH PROJECT, 2026
** display_cells
** File description:
** displays each cell based on the cell_t ** struct given
** and player pattern(s)
*/

#include <stdlib.h>

#include "config.h"
#include "my.h"

static void display_pattern_coordinates(settings_t *settings,
    int x, int y, ll_player_info_t *player_info)
{
    WINDOW *screen = settings->screen;
    wchar_t **pattern = player_info->pattern;
    int color = player_info->color;

    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    for (int i = 0; pattern[i] != NULL; i++)
        mvwprintw(screen, y + i, x, "%ls", pattern[i]);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}

static void place_token(settings_t *settings,
    int row, int column)
{
    ll_player_info_t *pl_ptr = NULL;
    cell_t cell = (settings->board)[row][column];
    int played_by = cell.taken;
    int *props = settings->proportions;
    int x_mid = (props[0] / 2) + 1;
    int y_mid = (props[1] / 2) + 1;
    int pos_x = (2 * x_mid * column) + 1 + props[2];
    int pos_y = (2 * y_mid * row) + 1;

    pl_ptr = get_player_from_turn(settings->player_info, played_by);
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
