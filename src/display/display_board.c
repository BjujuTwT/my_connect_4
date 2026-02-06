/*
** EPITECH PROJECT, 2026
** display_board
** File description:
** displays the whole board
*/

#include "config.h"
#include "my.h"
#include <wchar.h>


void display_board(settings_t *settings)
{
    FILE *fd = fopen("ressources/test", "r");
    char *buffer = NULL;
    size_t size = 0;
    long return_value = 0;
    WINDOW *screen = settings->screen;

    if (fd == NULL) {
        waddstr(screen, "KO");
        return;
    }
    return_value = getline(&buffer, &size, fd);
    while (return_value != -1) {
        wprintw(screen, "%s", buffer);
        return_value = getline(&buffer, &size, fd);
    }
    return;
}
