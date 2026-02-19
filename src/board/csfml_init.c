/*
** EPITECH PROJECT, 2026
** csfml_init
** File description:
** init function for the general structure csfml-orientated
*/

#include "config.h"
#include "macro_colors.h"

void csfml_init(settings_t *settings)
{
    display_help_examples(2);
    settings->to_terminate = 1;
    display_color("This option hasn't been implemented yet.\n", CRIMSON, 2);
    return;
}
