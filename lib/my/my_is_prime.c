/*
** EPITECH PROJECT, 2025
** my_is_prime
** File description:
** returns 1 if the number is prime,
** 0 if not
*/

int my_is_prime(int nb)
{
    int is_prime = 1;

    if (nb < 2) {
        return 0;
    }
    for (int p = 2; p < nb; p++) {
        if (nb % p == 0) {
            is_prime = 0;
        }
    }
    return is_prime;
}
