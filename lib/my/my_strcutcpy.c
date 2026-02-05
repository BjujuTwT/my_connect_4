/*
** EPITECH PROJECT, 2025
** my_strcutcpy
** File description:
** copies the content of the second string
** into the first one, ignoring the first n characters
** (same as : starting at index n)
*/

char *my_strcutcpy(char *dest, char const *src, int n)
{
    int j = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (i >= n) {
            dest[j] = src[i];
            j++;
        }
    }
    dest[j] = '\0';
    return dest;
}
