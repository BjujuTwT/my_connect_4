/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** displays a number
*/
#include <unistd.h>

static void my_put_a_char(char c)
{
    write(1, &c, 1);
}

static int display(long long nb, long long rev_nbr)
{
    int piv_nb;

    while (rev_nbr != 0) {
        piv_nb = (int)rev_nbr % 10;
        my_put_a_char((char)piv_nb + '0');
        rev_nbr = (rev_nbr - piv_nb) / 10;
    }
    while (nb != 0 && nb % 10 == 0) {
        my_put_a_char('0');
        nb = nb / 10;
    }
    return 0;
}

int my_put_nbr(long long int nb)
{
    long long int nb_copy = nb;
    long long int rev_nbr = 0;

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
    display(nb, rev_nbr);
    return 0;
}
