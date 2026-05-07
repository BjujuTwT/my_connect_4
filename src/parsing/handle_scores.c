/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** parses the score file and updates it
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "my.h"

static void init_scores_file(int fd, int nb_players)
{
    for (int player_id = 1; player_id <= nb_players; player_id++)
        dprintf(fd, "P%i:0\n", player_id);
    return;
}

static void write_where_read
(FILE *fd, char *line, int current_player, int current_score)
{
    if (line == NULL)
        fseek(fd, 0, SEEK_END);
    else
        fseek(fd, -(long)(strlen(line)), SEEK_CUR);
    fprintf(fd, "P%i:%i\n", current_player, current_score + 1);
    return;
}

static char *get_line(FILE *fd, int player_id)
{
    char *buffer = 0;
    size_t size = 0;
    long return_val = 0;
    int current_player = 1;

    return_val = getline(&buffer, &size, fd);
    while (current_player != player_id) {
        if (return_val == -1)
            write_where_read(fd, NULL, current_player, -1);
        if (buffer[0] == '\n' || buffer[0] == '\0')
            write_where_read(fd, buffer, current_player, -1);
        current_player += 1;
        return_val = getline(&buffer, &size, fd);
    }
    if (return_val == -1)
        return NULL;
    return buffer;
}

static void update_scores(int player_id)
{
    FILE *fd = fopen(SCORE_PATH, "r+");
    char *line = get_line(fd, player_id);
    int score = 0;

    if (line == NULL)
        write_where_read(fd, NULL, player_id, -1);
    else {
        if (line[0] == '\n' || line[0] == '\0')
            score = -1;
        else
            score = get_nbr_at_index(line, 3);
        write_where_read(fd, line, player_id, score);
        free(line);
    }
    fclose(fd);
    return;
}

void handle_scores(settings_t *settings)
{
    FILE *read_fd = fopen(SCORE_PATH, "r");
    char *buffer = NULL;
    int write_fd = 0;

    if (is_valid_score_file(read_fd, buffer) != 1) {
        write_fd = open(SCORE_PATH, O_CREAT | O_WRONLY | O_TRUNC);
        init_scores_file(write_fd, settings->nb_players);
        close(write_fd);
    }
    if (read_fd != NULL)
        fclose(read_fd);
    free(buffer);
    update_scores(settings->is_ended);
    return;
}
