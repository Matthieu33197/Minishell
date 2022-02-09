/*
** EPITECH PROJECT, 2019
** my
** File description:
** all my
*/

#ifndef __MY_H__
#define __MY_H__

#include <stddef.h>
#include <stdlib.h>

typedef struct nb_struct
{
    int i;
    int j;
    int n;
    int k;
    int mllc;
} nb;

int my_getnbr(char *nbr);
int my_strlen(const char *str);
void my_putchar(char c);
int my_putstr(char const *str);
void my_put_nbr(int nb);
int str_compare(const char *s1, char *s2);
void directory(char *command, char **env);
char **split_command(char *command, nb *go);
int check_exit(const char *command);
char *check_access(char *command, char **path);
char **get_path(char **env, nb *go);
void exec_cmd(char **command, char **env, char **path);

#endif