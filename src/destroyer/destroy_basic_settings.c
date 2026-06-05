/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** frees the allocated things in the basic
** settings function (init file)
*/

#include <stdlib.h>

#include "config.h"

void destroy_basic_settings(settings_t *settings)
{
    int height = settings->height;

    for (int i = 0; i < height; i++)
        free((settings->board)[i]);
    free(settings->board);
    free(settings->last_played);
    return;
}
