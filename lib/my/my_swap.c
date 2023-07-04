/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** ->   swaps two pointers
** ->   allowed function : my_putchar
*/

void my_swap(int *a, int *b)
{
    const int temp = *a;
    *a = *b;
    *b = temp;
}
