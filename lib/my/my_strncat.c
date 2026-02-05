/*
** EPITECH PROJECT, 2025
** my_strncat
** File description:
** concatenates n characters of the
** second parameter (str) into first
*/

static int that_other_other_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = that_other_other_strlen(dest);

    for (int i = 0; src[i] != '\0' && i < nb; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[that_other_other_strlen(dest)] = '\0';
    return dest;
}
