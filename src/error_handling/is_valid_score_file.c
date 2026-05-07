/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Verifies if the given score file is valid
*/

#include <stdio.h>

#include "my.h"
#include "config.h"

static int verify_line(char *line, int player_id)
{
    int score = 0;

    if (line[0] == '\n' && line[1] == '\0')
        return 0;
    if (my_lowercase(line[0]) != 'p')
        return -1;
    if ((line[1] - '0') != player_id)
        return -1;
    if (line[2] != ':')
        return -1;
    score = get_nbr_at_index(line, 3);
    if (score < 0)
        return -1;
    return 0;
}

int is_valid_score_file(FILE *fd, char *buffer)
{
    size_t size = 0;
    long return_val = 0;
    int nb_lines = 0;

    if (fd == NULL)
        return -1;
    return_val = getline(&buffer, &size, fd);
    while (return_val != -1 && nb_lines < MAX_PLAYERS) {
        if (verify_line(buffer, nb_lines + 1) == -1)
            return -1;
        nb_lines++;
        return_val = getline(&buffer, &size, fd);
    }
    if (nb_lines < 2)
        return -1;
    return 1;
}
