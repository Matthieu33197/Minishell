/*
** EPITECH PROJECT, 2020
** path and exe
** File description:
** path and exe
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

void exec_cmd(char **command, char **env, char **path)
{
    pid_t pid = 0;
    int i = 0;

    pid = fork();
    if (pid == -1)
        perror("fork");
    else if (pid > 0) {
        waitpid(pid, &i, 0);
        kill(pid, SIGTERM);
    } else {
        if (execve(check_access(command[0], path), command, env) == -1)
            perror("shell");
        exit(0);
    }
}

static char **mem_alloc_2d_array(void)
{
    int i = 0;
    char **new_str = malloc(sizeof(char *) * 500);

    while (i != 500) {
        new_str[i] = malloc(sizeof(char) * 500);
        i++;
    }
    return (new_str);
}

static void copy_path(char **env, char **path, nb *go)
{
    if (*env == NULL)
        exit(0);
    while (env[go->j][go->i] != '\0') {
        while (env[go->j][go->i] != ':' && env[go->j][go->i] != '\0') {
            path[go->n][go->k] = env[go->j][go->i];
            go->k++;
            go->i++;
        }
        go->i++;
        path[go->n][go->k] = '/';
        go->n++;
        go->k = 0;
    }
    path[go->n][go->k + 1] = '\0';
}

char **get_path(char **env, nb *go)
{
    go->i = 5;
    go->j = 0;
    go->n = 0;
    go->k = 0;
    char **path;

    path = mem_alloc_2d_array();
    while (env[go->j] != NULL) {
        if (env[go->j][0] == 'P' && env[go->j][1] == 'A' &&
            env[go->j][2] == 'T' && env[go->j][3] == 'H')
            break;
        else
            go->j++;
    }
    copy_path(env, path, go);
    return (path);
}