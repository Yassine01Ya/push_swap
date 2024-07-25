#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct s_data
{
    char *allarg;
}t_data;

typedef struct s_stack
{
    int *array;
    int count;
}t_stack;


char	**ft_split(char const *s, char c);
int str_len(char *string);
void ft_putendl(char *string, int fd);
void    ft_error(char *arg);
void    ft_free(char **args);
int ft_num(int i);
int check_signes(char *string);
int check_validate(char *string);
void    check_args_is_valid(char **args);
int	ft_word_count(char const *s, char c);
int check_duplicate(t_stack *stack);
void    get_args(t_data *data, int c, char ** v);
t_stack get_stack(char *args);
t_stack get_main_stack(t_data *data);
char *str_cat(char *string1, char *string2);
long at_oi(char *s);
void check_min_max(int counter, char **args);


#endif