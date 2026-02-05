/*
** EPITECH PROJECT, 2026
** display_error
** File description:
** displays an error msg in a specific color
*/

#include <unistd.h>

#include "my.h"
#include "macro_colors.h"

void display_error(char *msg, char *color)
{
    int color_len = my_strlen(color);
    int msg_len = my_strlen(msg);
    int white_len = my_strlen(WHITE);

    write(2, color, (size_t)color_len);
    write(2, msg, (size_t)msg_len);
    write(2, WHITE, (size_t)white_len);
    return;
}
