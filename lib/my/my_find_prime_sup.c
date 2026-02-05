/*
** EPITECH PROJECT, 2025
** my_find_prime_sup
** File description:
** returns the smallest prime
** greater than the integer in parameter
*/

static int is_prime(int nb)
{
    int is_it_a_prime = 1;

    if (nb < 2) {
        return 0;
    }
    for (int p = 2; p < nb; p++) {
        if (nb % p == 0) {
            is_it_a_prime = 0;
        }
    }
    return is_it_a_prime;
}

int my_find_prime_sup(int nb)
{
    int prime_num_found = 0;
    int n = nb;

    while (prime_num_found == 0) {
        if (is_prime(n) == 1) {
            prime_num_found = 1;
        } else {
            n++;
        }
    }
    return n;
}
