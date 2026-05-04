/*
** EPITECH PROJECT, 2026
** my
** File description:
** returns the char in lowercase if it was uppercase
*/

int my_lowercase(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}
