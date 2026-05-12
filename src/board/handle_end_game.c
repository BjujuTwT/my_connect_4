/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** updates the score in the appropriate file,
** and handles the game's last instructions
*/

#include "config.h"
#include "my.h"

static void display_tie(WINDOW *screen, int msg_x, int msg_y)
{
    int color = PREVIEW_NCURSES;

    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    mvwaddstr(screen, msg_y, msg_x, "It is a tie! ");
    wprintw(screen, "Press '%c' to restart", KEY_REPLAY);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}

static void display_text(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    int msg_x = settings->proportions[2];
    int msg_y = (settings->proportions[1]) * settings->height;
    ll_player_info_t *player = settings->player_info;

    msg_y += settings->height + 2;
    if (settings->is_ended == 0)
        return display_tie(screen, msg_x, msg_y);
    player = get_player_from_turn(player, settings->is_ended);
    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(player->color));
    mvwprintw(screen, msg_y, msg_x, "Player P%i has won! ", player->index);
    wprintw(screen, "Press %c to restart", KEY_REPLAY);
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
    while (input != KEY_EXIT1 && input != KEY_EXIT2) {
        //if (input != -1)
        //printf("%i: %c\n", input, input);
        if (input == KEY_REPLAY) {
            settings->restart = 1;
            return;
        }
        input = my_lowercase(wgetch(settings->screen));
    }
    return;
}
