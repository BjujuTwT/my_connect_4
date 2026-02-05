/*
** EPITECH PROJECT, 2025
** my_put_array
** File description:
** displays the content of an array, line per line
*/
#include <stddef.h>
#include <unistd.h>

static void that_putchar(char c)
{
    write(1, &c, 1);
}

static void that_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        that_putchar(str[i]);
    }
    return;
}

void my_put_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        that_putstr(array[i]);
        that_putchar('\n');
    }
    return;
}
