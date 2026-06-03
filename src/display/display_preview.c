/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Displays the next move that could be played
** at the current selected spot
*/

#include <stddef.h>
#include <stdio.h>

#include "config.h"
#include "my.h"
#include "macro_colors.h"

static void display_next_player_text
(settings_t *settings, int box_x, int box_y, ll_player_info_t *player)
{
    int len_msg = my_strlen("Next move: P0");
    int pos_x = box_x;
    int pos_y = box_y + 2 + settings->proportions[1];

    pos_x += (settings->proportions[0] + 2) / 2 - len_msg / 2;
    if (has_colors() == true)
        wattron(settings->screen, COLOR_PAIR(player->color));
    mvwprintw(settings->screen, pos_y, pos_x, "Next move: P%i", player->index);
    if (has_colors() == true)
        wattroff(settings->screen, COLOR_PAIR(player->color));
    return;
}

static void display_next_player_move(settings_t *settings)
{
    int box_x = (settings->proportions[0] + 1) * settings->width;
    int box_y = OFFSET_NEXT_MOVE_Y;
    int current_turn = (settings->player_turn % (settings->nb_players)) + 1;
    ll_player_info_t *player = NULL;

    if (settings->is_ended != -1)
        return;
    box_x += 1 + settings->proportions[2] + OFFSET_NEXT_MOVE_X;
    player = get_player_from_id(settings->player_info, current_turn);
    display_box_coordinates(settings, box_x, box_y);
    display_pattern_coordinates(settings, box_x + 1, box_y + 1, player);
    display_next_player_text(settings, box_x, box_y, player);
}

void display_preview(settings_t *settings, WINDOW *screen)
{
    int arrow_col = settings->col_arrow;
    int highest_token = get_highest_played(settings, arrow_col);
    int pos_x = 0;
    int pos_y = 0;
    ll_player_info_t *player = NULL;

    display_next_player_move(settings);
    if (highest_token == -1)
        return;
    pos_x = get_x_from_column(settings, arrow_col);
    pos_y = get_y_from_row(settings, highest_token);
    player = get_player_from_id(settings->player_info, settings->player_turn);
    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(PAIR_PREVIEW));
    for (int i = 0; (player->pattern)[i] != NULL; i++)
        mvwprintw(screen, pos_y + i, pos_x, "%ls", (player->pattern)[i]);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(PAIR_PREVIEW));
}
