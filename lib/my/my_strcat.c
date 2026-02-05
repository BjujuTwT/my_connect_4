/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concatenates two strings togetha
*/

static int that_other_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int len_dest = that_other_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[that_other_strlen(dest)] = '\0';
    return dest;
}
