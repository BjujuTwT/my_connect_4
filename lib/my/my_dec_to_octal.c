/*
** EPITECH PROJECT, 2025
** my_dec_to_octal
** File description:
** returns the integer in base 10 in argument to
** an integer in base 8
*/

int my_dec_to_octal(int nb)
{
    if ((nb / 8) == 0)
        return nb % 8;
    return ((nb % 8) + 10 * my_dec_to_octal(nb / 8));
}
