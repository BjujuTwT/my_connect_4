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


static int get_highest_played(settings_t *settings, int col)
{
    int height = settings->height;
    cell_t **board = settings->board;

    for (int row = height - 1; row >= 0; row--) {
        if (board[row][col - 1].taken == 0)
            return row + 1;
    }
    return -1;
}

static void display_preview(settings_t *settings, WINDOW *screen)
{
    int arrow_col = settings->col_arrow;
    int highest_token = get_highest_played(settings, arrow_col);
    int pos_x = 0;
    int pos_y = 0;
    ll_player_info_t *player = NULL;

    if (highest_token == -1)
        return;
    pos_x = get_x_from_column(settings, arrow_col);
    pos_y = get_y_from_row(settings, highest_token);
    player = get_player_from_turn(settings->player_info, settings->player_turn);
    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(PREVIEW_COL));
    for (int i = 0; (player->pattern)[i] != NULL; i++)
        mvwprintw(screen, pos_y + i, pos_x, "%ls", (player->pattern)[i]);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(PREVIEW_COL));
    return;
}

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
    int pos_x = get_x_from_column(settings, column + 1);
    int pos_y = get_y_from_row(settings, row + 1);

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
    display_preview(settings, settings->screen);
    return;
}
