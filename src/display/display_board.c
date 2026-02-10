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

static void display_file_in_screen(char *file, WINDOW *screen)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    size_t size = 0;
    long return_value = 0;

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

void put_dots(settings_t *settings, WINDOW *screen, int width, int height)
{
    int offset = settings->proportions[2];
    int x_mid = (width / 2) + 1;
    int y_mid = (height / 2) + 1;
    int pos_x = 0;
    int pos_y = 0;

    for (int cellx_i = 0; cellx_i < settings->width; cellx_i++) {
        pos_x = (2 * x_mid * cellx_i) + 1 + offset;
        for (int celly_i = 0; celly_i < settings->height; celly_i++) {
            pos_y = (2 * y_mid * celly_i) + 1;
            mvwaddstr(screen, pos_y, pos_x, "-");
        }
    }
    return;
}

static void display_pattern_coordinates(WINDOW *screen,
    int y, int x, ll_player_info_t *player_info)
{
    wchar_t **pattern = player_info->pattern;

    for (int i = 0; pattern[i] != NULL; i++)
        mvwprintw(screen, y + i, x, "%ls", pattern[i]);
    return;
}

void display_board(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    int width = settings->proportions[0];
    int height = settings->proportions[1];

    display_file_in_screen("ressources/template", screen);
    put_dots(settings, screen, width, height);
    mvwaddstr(screen, 15, 116, "╔");
    mvwaddstr(screen, 15, 116 + width + 1, "╗");
    display_pattern_coordinates(screen, 16, 117, settings->player_info);
    mvwaddstr(screen, 15 + height + 1, 116, "╚");
    mvwaddstr(screen, 15 + height + 1, 116 + width + 1, "╝");
    return;
}
