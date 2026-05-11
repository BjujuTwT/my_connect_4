/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** displays all player's scores in the console
*/

#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "config.h"
#include "macro_colors.h"

static int get_biggest_nb(scores_t *score_list)
{
    int biggest_nb = score_list->p1;

    if (score_list->p2 > biggest_nb)
        biggest_nb = score_list->p2;
    if (score_list->p3 > biggest_nb)
        biggest_nb = score_list->p3;
    if (score_list->p4 > biggest_nb)
        biggest_nb = score_list->p4;
    return biggest_nb;
}

static void display_scores_with_colors(scores_t *curr_scores)
{
    int size_nb = my_intlen(get_biggest_nb(curr_scores));

    if (curr_scores->p1 > -1) {
        display_color("P1: ", P1, 1);
        printf("%*i\n", size_nb, curr_scores->p1);
    }
    if (curr_scores->p2 > -1) {
        display_color("P2: ", P2, 1);
        printf("%*i\n", size_nb, curr_scores->p2);
    }
    if (curr_scores->p3 > -1) {
        display_color("P3: ", P3, 1);
        printf("%*i\n", size_nb, curr_scores->p3);
    }
    if (curr_scores->p4 > -1) {
        display_color("P4: ", P4, 1);
        printf("%*i\n", size_nb, curr_scores->p4);
    }
    return;
}

int display_scores(void)
{
    FILE *fd = fopen(SCORE_PATH, "rb");
    scores_t *curr_scores = NULL;

    if (fd == NULL) {
        display_file_unavailable(SCORE_PATH);
        display_color("Make sure to play at least one game\n", CYAN, 2);
        return 84;
    }
    if (verify_scores() < 0) {
        fclose(fd);
        return 84;
    }
    curr_scores = malloc(sizeof(scores_t));
    fread(curr_scores, sizeof(scores_t), 1, fd);
    display_scores_with_colors(curr_scores);
    fclose(fd);
    free(curr_scores);
    return 1;
}
