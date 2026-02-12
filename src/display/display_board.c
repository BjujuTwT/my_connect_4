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
#include <stdio.h>
#include <stdlib.h>

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
    int x, int y, ll_player_info_t *player_info)
{
    wchar_t **pattern = player_info->pattern;

    for (int i = 0; pattern[i] != NULL; i++)
        mvwprintw(screen, y + i, x, "%ls", pattern[i]);
    return;
}

void place_token(settings_t *settings, int row, int column)
{
    cell_t **board = settings->board;
    WINDOW *screen = settings->screen;
    ll_player_info_t *player = settings->player_info;
    int *props = settings->proportions;
    int x_mid = (props[0] / 2) + 1;
    int y_mid = (props[1] / 2) + 1;
    int pos_x = (2 * x_mid * column) + 1 + props[2];
    int pos_y = (2 * y_mid * row) + 1;

    if (board[row][column].taken != 0)
        display_pattern_coordinates(screen, pos_x, pos_y, player);
    return;
}

void display_cells(settings_t *settings)
{
    int width = settings->width;
    int height = settings->height;

    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++)
            place_token(settings, row, column);
    }
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
    display_pattern_coordinates(screen, 117, 16, settings->player_info);
    mvwaddstr(screen, 15 + height + 1, 116, "╚");
    mvwaddstr(screen, 15 + height + 1, 116 + width + 1, "╝");
    display_cells(settings);
    return;
}
