/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** updates the score in the appropriate file,
** and handles the game's last instructions
*/

#include "config.h"
#include "my.h"

void handle_end_game(settings_t *settings)
{
    int input = -1;

    write_scores(settings);
    input = my_lowercase(wgetch(settings->screen));
    while (input != EXIT_KEY1 && input != EXIT_KEY2) {
        input = my_lowercase(wgetch(settings->screen));
    }
    endwin();
    return;
}
