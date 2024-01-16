#include "sort.h"

/**
 * _swap - Swap two numbers.
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 **/
void _swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * _split - Split the array and take the last element as the pivot.
 * @arr: Array to be sorted
 * @min: Index of the first element
 * @last: Index of the last element
 * @size: Size of the array
 * Return: The index of the pivot after partitioning
 **/
int _split(int *arr, int min, int last, size_t size)
{
    int piv;
    int i = (min);
    int j;

    piv = arr[last];

    for (j = min; j < last; j++)
    {
        if (arr[j] <= piv)
        {
            _swap(&arr[i], &arr[j]);

            if (i != j)
                print_array(arr, size);

            i++;
        }
    }

    _swap(&arr[i], &arr[last]);
    if (i != j)
        print_array(arr, size);

    return i;
}

/**
 * quick_sort_array - Implementation of the quicksort algorithm on an array.
 * @arr: Array to be sorted
 * @min: Index of the first element
 * @last: Index of the last element
 * @size: Size of the array
 * Return: Nothing
 */
void quick_sort_array(int *arr, int min, int last, size_t size)
{
    int piv;

    if (min < last)
    {
        piv = _split(arr, min, last, size);
        quick_sort_array(arr, min, (piv - 1), size);
        quick_sort_array(arr, (piv + 1), last, size);
    }
}

/**
 * quick_sort - Sort an array using the quicksort algorithm.
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    quick_sort_array(array, 0, size - 1, size);
}

