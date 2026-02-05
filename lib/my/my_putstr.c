/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** Task2, displays one by one the characters of a string
*/
#include <unistd.h>

static size_t my3_strlen(char const *str)
{
    size_t i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int my_putstr(char const *str)
{
    size_t len = my3_strlen(str);

    write(1, str, len);
    return 0;
}
