/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** copies n amount of characters from the
** string in second argument to the first
*/

static int this_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    if (n > this_strlen(src)) {
        dest[i] = '\0';
    }
    return dest;
}
