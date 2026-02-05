/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include <ncurses.h>

#include "config.h"
#include "my.h"

WINDOW *ncurses_init(void)
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

void display_board(WINDOW *screen)
{
    wprintw(screen, "OK");
    return;
}

int main(int argc, char **argv)
{
    WINDOW *screen;

    if (error_handler(argc, argv) != 0)
        return 84;
    screen = ncurses_init();
    while (isendwin() == FALSE) {
        werase(screen);
        display_board(screen);
        wrefresh(screen);
        wait_for_next_move(screen);
    }
    endwin();
    return 0;
}
