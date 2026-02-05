/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** copies the content of the second
** pointer into the first one in parameter
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
