/*
** EPITECH PROJECT, 2025
** my
** File description:
** contains the prototypes of the 30
** func from the library my
*/

#ifndef MY_STR_PROTOTYPES_H_
    #define MY_STR_PROTOTYPES_H_
    #include <unistd.h>
    #include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(long long int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int *my_merge_sort(int *arr, unsigned len);
float my_compute_power_rec(int nb, int p);
double my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_intlen(long long int n);
float my_floatncmp(float f1, float f2, unsigned int n);
int my_find_c_in_str(char c, char *str);
char *my_strcutcpy(char *dest, char const *src, int n);
void my_put_2d_array(char **array, int nb_rows, int nb_cols);
int my_find_n_in_array(int nb, int *array, int size);
void my_put_int_array(int *array, int size);
int my_max(int n1, int n2);
int my_min(int n1, int n2);

#endif /* MY_STR_PROTOTYPES_ */
