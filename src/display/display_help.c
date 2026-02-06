/*
** EPITECH PROJECT, 2026
** display_help
** File description:
** displays all necessary informations
*/

#include "my.h"
#include "macro_colors.h"
#include "config.h"

static int display_file_content(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buffer = NULL;
    size_t size = 0;
    long return_value = 0;

    if (fd == NULL) {
        display_color("Ressource files are unavailable.\n", CRIMSON, 2);
        display_color("Missing : ", CRIMSON, 2);
        display_color(filepath, CYAN, 2);
        write(2, "\n", 1);
        return 84;
    }
    return_value = getline(&buffer, &size, fd);
    while (return_value != -1) {
        my_putstr(buffer);
        return_value = getline(&buffer, &size, fd);
    }
    return 0;
}

int display_help(char language)
{
    int return_value = 0;

    display_help_examples(1);
    my_putstr("\n\n");
    if (language == 'f')
        return_value = display_file_content("ressources/french_menu");
    if (language == 'h')
        return_value = display_file_content("ressources/english_menu");
    if (return_value != 0)
        return 84;
    return 1;
}
