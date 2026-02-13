/*
** EPITECH PROJECT, 2026
** display_cells
** File description:
** displays each cell based on the cell_t ** struct given
** and player pattern(s)
*/

#include "config.h"
#include "my.h"

static void display_pattern_coordinates(WINDOW *screen,
    int x, int y, ll_player_info_t *player_info)
{
    wchar_t **pattern = player_info->pattern;

    for (int i = 0; pattern[i] != NULL; i++)
        mvwprintw(screen, y + i, x, "%ls", pattern[i]);
    return;
}

static void place_token(settings_t *settings, int row, int column)
{
    cell_t **board = settings->board;
    WINDOW *screen = settings->screen;
    ll_player_info_t *player = settings->player_info;
    int *props = settings->proportions;
    int x_mid = (props[0] / 2) + 1;
    int y_mid = (props[1] / 2) + 1;
    int pos_x = (2 * x_mid * column) + 1 + props[2];
    int pos_y = (2 * y_mid * row) + 1;

    if (board[row][column].taken != 0)
        display_pattern_coordinates(screen, pos_x, pos_y, player);
    return;
}

void display_cells(settings_t *settings)
{
    int width = settings->width;
    int height = settings->height;

    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++)
            place_token(settings, row, column);
    }
    return;
}
