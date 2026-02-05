/*
** EPITECH PROJECT, 2025
** my_merge_sort
** File description:
** sorts an int array in ascending order
*/
#include <stdlib.h>

static int *array_cut(int *array, unsigned from, unsigned to)
{
    unsigned dest_len = to - from + 1;
    int *dest = malloc(sizeof(int *) * dest_len);

    for (unsigned i = from; i < to; i++)
        dest[i - from] = array[i];
    return dest;
}

static int *merge(int *arr1, int *arr2, unsigned l1, unsigned l2)
{
    unsigned i = 0;
    unsigned j = 0;
    unsigned arr_len = (unsigned)(l1 + l2);
    int *arr = malloc(sizeof(int) * arr_len);

    while (i != l1 || j != l2) {
        if ((arr1[i] <= arr2[j] || j == l2) && i != l1) {
            arr[i + j] = arr1[i];
            i++;
        } else {
            arr[i + j] = arr2[j];
            j++;
        }
    }
    return arr;
}

int *my_merge_sort(int *arr, unsigned len)
{
    unsigned l_first = (len / 2) + (len % 2);
    int *arr_left = malloc(sizeof(int) * l_first);
    int *arr_right = malloc(sizeof(int) * (len - l_first));

    if (len == 1)
        return arr;
    arr_left = my_merge_sort(array_cut(arr, 0, l_first), l_first);
    arr_right = my_merge_sort(array_cut(arr, l_first, len), len - l_first);
    return merge(arr_left, arr_right, l_first, len - l_first);
}
