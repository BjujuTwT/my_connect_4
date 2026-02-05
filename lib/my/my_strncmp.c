/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** sends the (ascii) comparison between the
** two strings in parameters, ending
** at n, being the 3rd parameter
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        if (i == n - 1) {
            return (s1[i] - s2[i]);
        }
    }
    return (s1[i] - s2[i]);
}
