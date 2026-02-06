/*
** EPITECH PROJECT, 2026
** display_color.c
** File description:
** displays in color a text
*/

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

void display_help_examples(int std)
{
    char *msg_en = "Try : ./connect_4 -h\n\0";
    char *msg_fr = "Essayez : ./connect_4 -f\n\0";

    display_color(msg_en, RED, std);
    display_color(msg_fr, BLUE, std);
    return;
}
