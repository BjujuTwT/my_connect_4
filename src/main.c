/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include <ncurses.h>

#include "my.h"

WINDOW *ncurse_init(void)
{
    WINDOW *screen = initscr();

    noecho();
    nodelay(screen, true);
    if (has_colors() == true) {
        start_color();
        use_default_colors();
    }
    return screen;
}

int main(void)
{
    WINDOW *screen;

    my_putstr("OK\n");
    endwin();
    return 0;
}
