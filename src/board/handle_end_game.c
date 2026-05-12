/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** updates the score in the appropriate file,
** and handles the game's last instructions
*/

#include "config.h"
#include "my.h"

static void display_text(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    int msg_x = settings->proportions[2];
    int msg_y = (settings->proportions[1]) * settings->height;
    ll_player_info_t *player = settings->player_info;

    msg_y += settings->height + 2;
    player = get_player_from_turn(player, settings->is_ended);
    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(player->color));
    mvwprintw(screen, msg_y, msg_x, "Player P%i has won!", player->index);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(player->color));
    return;
}

void handle_end_game(settings_t *settings)
{
    int input = -1;

    handle_scores(settings);
    display_text(settings);
    input = my_lowercase(wgetch(settings->screen));
    while (input != EXIT_KEY1 && input != EXIT_KEY2) {
        input = my_lowercase(wgetch(settings->screen));
    }
    endwin();
    return;
}
