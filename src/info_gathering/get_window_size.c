/*
** EPITECH PROJECT, 2026
** get_window_size
** File description:
** uses a non-Epitech coding style function, and also doesn't switch x and y
*/

#include "config.h"

void get_window_size(WINDOW *screen, int *x, int *y)
{
    getmaxyx(screen, *y, *x);
    return;
}
