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
#include <curses.h>

#include "config.h"
#include "my.h"

static void disp_line(WINDOW *screen, settings_t *settings,
    int line, char **corners)
{
    int width = settings->width;
    int cell_w = settings->proportions[0];
    int line_w = (width * cell_w) + width + 1;
    int offset = settings->proportions[2];

    mvwaddstr(screen, line, offset, corners[0]);
    for (int char_line = 1; char_line < line_w; char_line += cell_w + 1) {
        for (int char_cell = 0; char_cell < cell_w; char_cell++)
            waddstr(screen, corners[2]);
        if (char_line + cell_w + 1 != line_w)
            waddstr(screen, corners[1]);
    }
    waddstr(screen, corners[3]);
    return;
}

static char **corner_array(char *corner1, char *corner2,
    char *corner3, char *corner4)
{
    size_t nb_elem = 4;
    char **wstruct = malloc(sizeof(char *) * (nb_elem + 1));

    wstruct[0] = corner1;
    wstruct[1] = corner2;
    wstruct[2] = corner3;
    wstruct[3] = corner4;
    return wstruct;
}

void display_board(WINDOW *screen, settings_t *settings)
{
    int height = settings->height;
    int cell_h = settings->proportions[1];
    int nb_lines = (height * cell_h) + height + 1;
    char **corner_up = corner_array("╔", "╦", "─", "╗");
    char **corner_basic = corner_array("│", "│", " ", "│");
    char **corner_middle = corner_array("╠", "╬", "─", "╣");
    char **corner_down = corner_array("╚", "╩", "─", "╝");

    disp_line(screen, settings, 0, corner_up);
    for (int line_i = 1; line_i + 1 < nb_lines; line_i++) {
        if (line_i % (cell_h + 1) == 0)
            disp_line(screen, settings, line_i, corner_middle);
        else
            disp_line(screen, settings, line_i, corner_basic);
    }
    disp_line(screen, settings, nb_lines - 1, corner_down);
    return;
}
