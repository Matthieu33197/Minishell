/*
** EPITECH PROJECT, 2020
** my func
** File description:
** my func
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_getnbr(char *nbr)
{
    int i = 0;
    int j = 0;

    if (nbr[0] && nbr[0] == '-')
        i++;
    while (nbr[i]) {
        if ((nbr[i] < '0' || nbr[i] > '9'))
            return (0);
        j += nbr[i] - 48;
        j *= 10;
        i++;
    }
    j /= 10;
    if (nbr[0] == '-')
        return (-1 * j);
    else
        return (j);
}
