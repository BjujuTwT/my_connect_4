/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** returns a pointer to the position of the
** first occurence of the second
** parameter in the first
*/
#include <stddef.h>

static int my_other_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

static char *our_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    if (n > my_other_strlen(src)) {
        dest[i] = '\0';
    }
    return dest;
}

static int our_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (s1[i] - s2[i]);
}

char *my_strstr(char *str, char const *to_find)
{
    char loop_str[my_other_strlen(to_find)];

    for (int i = 0; str[i] != '\0'; i++) {
        our_strncpy(loop_str, &str[i], my_other_strlen(to_find));
        if (our_strcmp(loop_str, to_find) == 0) {
            return &str[i];
        }
    }
    return NULL;
}
