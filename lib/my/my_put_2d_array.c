/*
** EPITECH PROJECT, 2025
** my_put_2d_array
** File description:
** displays the content of each
** row of a 2d array, separed by a '\n'
*/
#include <unistd.h>

static void our_put_a_char(char c)
{
    write(1, &c, 1);
}

void my_put_2d_array(char **array, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++)
            our_put_a_char(array[i][j]);
        our_put_a_char('\n');
    }
    return;
}
