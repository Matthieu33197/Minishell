/*
** EPITECH PROJECT, 2019
** my2.c
** File description:
** my2.c
*/

#include <unistd.h>
#include "my.h"

int neg(int i)
{
    if (i == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        i = 147483648;
    }
    if (i < 0) {
        i = i * -1;
        my_putchar('-');
    }
    return (i);
}

void my_put_nbr(int nb)
{
    nb = neg(nb);
    if (nb < 10)
        my_putchar(nb + '0');
    else {
        my_put_nbr(nb/10);
        my_put_nbr(nb%10);
    }
}

int str_compare(const char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    i++;
    if (i == my_strlen(s1))
        return (1);
    else
        return (0);
}
