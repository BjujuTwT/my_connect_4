/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include <stdlib.h>

#include "config.h"
#include "my.h"

static void free_func(settings_t *settings)
{
    int height = settings->height;

    for (int i = 0; i < height; i++)
        free((settings->board)[i]);
    free(settings->board);
    return;
}

int main(int argc, char **argv)
{
    settings_t settings;

    if (error_handler(argc, argv) != 0)
        return 84;
    settings = init(argv[1][1]);
    if (settings.to_terminate != 0)
        return settings.to_terminate;
    while (isendwin() == FALSE) {
        waddstr(settings.screen, "!");
        werase(settings.screen);
        display_ncurses(&settings);
        wrefresh(settings.screen);
        wait_for_next_move(&settings);
    }
    endwin();
    free_func(&settings);
    return 0;
}
