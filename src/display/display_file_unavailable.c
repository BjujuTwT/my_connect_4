/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** displays a given unavailable filepath in the console
*/

#include <unistd.h>

#include "config.h"
#include "macro_colors.h"

void display_file_unavailable(char *filepath)
{
    display_color("Ressource files are unavailable.\n", CRIMSON, 2);
    display_color("Missing : ", CRIMSON, 2);
    display_color(filepath, CYAN, 2);
    write(2, "\n", 1);
    return;
}
