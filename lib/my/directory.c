/*
** EPITECH PROJECT, 2020
** directory
** File description:
** directory
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

static void copy_home(char **env, int j)
{
    int i = 5;
    int k = 0;
    char *home = malloc(sizeof(char) * (my_strlen(env[j]) - 4));
    if (*env == NULL)
        exit(0);
    while (env[j][i] != '\0') {
            home[k] = env[j][i];
            k++;
            i++;
    }
    home[k] = '\0';
    if (chdir(home) == -1)
            perror("chdir()");
}

static void home(char **env)
{
    int j = 0;
    while (env[j] != NULL) {
        if (env[j][0] == 'H' && env[j][1] == 'O' &&
            env[j][2] == 'M' && env[j][3] == 'E')
            break;
        else
            j++;
    }
    copy_home(env, j);
}

void directory(char *command, char **env)
{
    char *str = malloc(sizeof(char) * my_strlen(command));
    int i = 0;
    int j = 0;

    if (my_strlen(command) > 2) {
        while (command[i] != ' ')
            i++;
        i++;
        while (command[i] != '\0') {
            str[j] = command[i];
            i++;
            j++;
        }
        str[j] = '\0';
        if (chdir(str) == -1)
            perror("chdir()");
    } else
    home(env);
}