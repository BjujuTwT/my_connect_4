/*
** EPITECH PROJECT, 2026
** display_board
** File description:
** displays the whole board
** ╔─╦─╗
** │ │ │
** ╠─╬─╣
** │ │ │
** ╚─╩─╝
** ╔───╦───╗
** │   │   │
** ╠───╬───╣
** │   │   │1
** ╚───╩───╝
**      123
*/

#include <wchar.h>

#include "config.h"
#include "my.h"

static void display_file_in_screen(char *file, settings_t *settings)
{
    FILE *fd = fopen(file, "r");
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

void display_board(settings_t *settings)
{
    display_file_in_screen("ressources/template", settings);
    return;
}
