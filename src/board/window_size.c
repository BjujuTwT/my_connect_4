/*
** EPITECH PROJECT, 2026
** window_size
** File description:
** all functions to setup the window's size, by asking the user
*/

#include <stdlib.h>

#include "my.h"
#include "config.h"

static void display_request(WINDOW *screen, int x_max, int y_max)
{
    char msg1[] = "Window size?\0";
    char msg2[] = "Number between 1 and 4 (default : 'ENTER') :\0";
    int x_pos = 0;
    int y_pos = 0;

    x_pos = x_max / 2 - my_strlen(msg1) / 2;
    y_pos = y_max / 2 - 1;
    mvwaddstr(screen, y_pos, x_pos, msg1);
    x_pos = x_max / 2 - (my_strlen(msg2) / 2);
    y_pos += 1;
    mvwaddstr(screen, y_pos, x_pos, msg2);
    wrefresh(screen);
    return;
}

static int get_size_from_user(WINDOW *screen)
{
    int x_max = 0;
    int y_max = 0;
    int size = -1;
    int default_size = 2;

    get_window_size(screen, &x_max, &y_max);
    display_request(screen, x_max, y_max);
    while (size < 0 || size > 3) {
        size = getch();
        if (size == 'q' || size == 'Q')
            break;
        if (size == '\n') {
            size = default_size;
            break;
        }
        size = size - '0' - 1;
    }
    return size;
}

void setup_window_size(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    size_t dimensions = 2 + 1;
    int size = get_size_from_user(screen);

    if (size == 'q' || size == 'Q') {
        endwin();
        settings->to_terminate = -1;
        return;
    }
    settings->proportions = malloc(sizeof(int) * dimensions);
    settings->proportions[0] = size * 2 + 7;
    settings->proportions[1] = size + 3;
    settings->proportions[2] = 1;
    return;
}
