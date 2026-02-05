/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** sends the (ascii) comparison between the two strings
** (even if not same length)
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (s1[i] - s2[i]);
}
