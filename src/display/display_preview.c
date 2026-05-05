/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Displays the next move that could be played
** at the current selected spot
*/

//#include <stddef.h>

#include "config.h"

void display_preview(settings_t *settings, WINDOW *screen)
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
        wattron(screen, COLOR_PAIR(PREVIEW_COLOR));
    for (int i = 0; (player->pattern)[i] != NULL; i++)
        mvwprintw(screen, pos_y + i, pos_x, "%ls", (player->pattern)[i]);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(PREVIEW_COLOR));
}
