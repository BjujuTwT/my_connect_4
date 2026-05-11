/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Verifies if the given score file is valid
*/

#include <stdio.h>

#include "macro_colors.h"
#include "config.h"

int verify_scores(int display_errors)
{
    FILE *fd = fopen(SCORE_PATH, "rb");
    scores_t scores;
    size_t struct_size = sizeof(scores);
    size_t return_val = 0;

    if (fd == NULL)
        return -1;
    return_val = fread(&scores, struct_size, 1, fd);
    fclose(fd);
    if (return_val != 1)
        return -1;
    if (scores.p1 < -1 || scores.p2 < -1 || scores.p3 < -1 || scores.p4 < -1) {
        if (display_errors != 1)
            return -1;
        display_color("Invalid scores file.\n", CRIMSON, 2);
        display_color("Please try playing once to fix it.\n", CRIMSON, 2);
        return -1;
    }
    return 0;
}
