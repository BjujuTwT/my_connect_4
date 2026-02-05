/*
** EPITECH PROJECT, 2025
** my_put_2d_int_array
** File description:
** displays the content of an int array, line per line,
** with commas in between numbers
*/
#include <stddef.h>
#include <unistd.h>

static void my_put_a_char(char c)
{
    write(1, &c, 1);
}

static int display(long long nb, long long rev_nbr, long long piv_nb)
{
    while (rev_nbr != 0) {
        piv_nb = rev_nbr % 10;
        my_put_a_char(piv_nb + '0');
        rev_nbr = (rev_nbr - piv_nb) / 10;
    }
    while (nb != 0 && nb % 10 == 0) {
        my_put_a_char('0');
        nb = nb / 10;
    }
    return 0;
}

static int our_put_nbr(long long int nb)
{
    long long int nb_copy = nb;
    long long int rev_nbr = 0;
    long long int pivot_nbr;

    if (nb < 0) {
        my_put_a_char('-');
        nb_copy = nb_copy * -1;
    }
    if (nb == 0) {
        my_put_a_char('0');
    }
    while (nb_copy != 0) {
        rev_nbr = rev_nbr * 10 + (nb_copy % 10);
        nb_copy = (nb_copy - (nb_copy % 10)) / 10;
    }
    display(nb, rev_nbr, pivot_nbr);
    return 0;
}

static void my_put_int_array(int *array, int nb_cols)
{
    for (int j = 0; j < nb_cols; j++) {
        our_put_nbr(array[j]);
        if (j + 1 < nb_cols) {
            my_put_a_char(',');
            my_put_a_char(' ');
        }
    }
    return;
}

void my_put_2d_int_array(int **array, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        my_put_int_array(array[i], nb_cols);
        my_put_a_char('\n');
    }
    return;
}
