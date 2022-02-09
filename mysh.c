/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell1
*/

#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include "lib/my/my.h"

static void print_env(char **env)
{
    int j = 0;

    while(env[j] != NULL) {
        my_putstr(env[j]);
        my_putchar('\n');
        j++;
    }
}

static int choose_exec(char *command, char **env, char **cmd, nb *go)
{
    char **path;

    path = get_path(env, go);
    if (command[0] == 'c' && command[1] == 'd')
        directory(command, env);
    else if (command[0] == 'e' && command[1] == 'n' && command[2] == 'v')
        print_env(env);
    else
        exec_cmd(cmd, env, path);
    return (0);
}

static char *delete_space(char *command)
{
    char *newstr;
    int n = 0;
    int i = 0;

    while (command[i] == ' ' || command[i] == '\t')
        i++;
    newstr = malloc(sizeof(char) * (my_strlen(command) - i));
    for (int j = 0; command[j] != '\0'; j++) {
        if (command[j] != ' ' && command[j] != '\0' && command[j] != '\t') {
            newstr[n] = command[j];
            command[j] != '\0' ? n++ : 0;
        } else if (command[j] == ' ' && command[j - 1] >= 'a' &&
        command[j - 1] <= 'z') {
            newstr[n] = command[j];
            n++;
        }
        if (command[j] == '\t' && command[j - 1] >= 'a' &&
            command[j - 1] <= 'z') {
            newstr[n] = ' ';
            n++;
        }
    }
    newstr[n - 1] = '\0';
    return (newstr);
}

static int shell(char **env)
{
    char *command = NULL;
    char **cmd;
    size_t commanda = 0;
    nb *go = malloc(sizeof(nb));

    while (42) {
        my_putstr("$> ");
        if (getline(&command, &commanda, stdin) <= -1)
            return (84);
        if (check_exit(command) == 1)
            break;
        command = delete_space(command);
        cmd = split_command(command, go);
        choose_exec(command, env, cmd, go);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    (void) av;
    if (ac == 1)
        return (shell(env));
    return (0);
}