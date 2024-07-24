#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void ft_putendl(char *string, int fd);
void    ft_error(char *arg);
void    ft_free(char **args);
int ft_num(int i);
int check_signes(char *string);
int check_validate(char *string);
void    check_args_is_valid(char **args);

// typedef struct s_data
// {
//     char *allarg;
// }t_data

#endif