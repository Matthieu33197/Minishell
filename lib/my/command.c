/*
** EPITECH PROJECT, 2020
** command
** File description:
** command
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

static void take_command(char *command, char **cmd, nb *go)
{
    for (int i = 0; i <= go->mllc; i++)
        cmd[i] = malloc(sizeof(char) * 80);
    while (command[go->i] != '\0') {
        while (command[go->i] != ' ' && command[go->i] != '\0') {
            cmd[go->j][go->n] = command[go->i];
            go->i++;
            go->n++;
        }
        if (command[go->i] != '\0')
            go->i++;
        if (command[go->i] != ' ') {
            cmd[go->j][go->n] = '\0';
            go->n = 0;
            go->j++;
        }
    }
    cmd[go->j] = NULL;
}

char **split_command(char *command, nb *go)
{
    char **cmd;
    go->i = 0;
    go->j = 0;
    go->n = 0;
    go->mllc = 1;

    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == ' ' && command[i - 1] >= 'a' && command[i - 1] <= 'z')
            go->mllc++;
    cmd = malloc(sizeof(char *) * (go->mllc + 1));
    take_command(command, cmd, go);
    return (cmd);
}