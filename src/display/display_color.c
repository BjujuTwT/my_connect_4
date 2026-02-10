/*
** EPITECH PROJECT, 2026
** display_color.c
** File description:
** displays in color a text
*/

#include "config.h"
#include "my.h"
#include "macro_colors.h"

void display_color(char *msg, char *color, int std)
{
    int color_len = my_strlen(color);
    int msg_len = my_strlen(msg);
    int white_len = my_strlen(WHITE);

    write(std, color, (size_t)color_len);
    write(std, msg, (size_t)msg_len);
    write(std, WHITE, (size_t)white_len);
    return;
}
