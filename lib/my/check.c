/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include "my.h"

int check_exit(const char *command)
{
    char *exit = "exit";

    return (str_compare(command, exit));
}

char *check_access(char *command, char **path)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n = -1;

    while (n != 0) {
        i = my_strlen(path[j]);
        while (command[k] != '\0') {
            path[j][i] = command[k];
            i++;
            k++;
        }
        path[j][i] = '\0';
        n = access(path[j], X_OK);
        if (n == -1) {
            j++;
            k = 0;
        }
    }
    return (path[j]);
}
