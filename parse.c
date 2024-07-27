#include "push_swap.h"


void    get_args(t_data *data, int c, char ** v)
{
    int i;
    int length;

    i = 1;
    length = 0;
    while (i < c)
    {
        if (v[i][0] == 0 || !v[i])
            ft_error("Error");
        length += str_len(v[i]);
        i++;
    }
    length++;
    data->allarg = (char *)malloc(sizeof (char) * (length + c ));
    if(!data->allarg)
        exit(EXIT_FAILURE);
    i = 1;
    data->allarg[0]='\0';
    while (v[i] && i < c)
    {
        str_cat(data->allarg, v[i]);
        if (i < c - 1)
            str_cat(data->allarg, " ");
        i++;
    }
}

t_stack get_stack(char *args)
{
    t_stack res;
    char **split;
    int word_count;

    word_count = ft_word_count(args, ' ');
    split = ft_split(args, ' ');
    if (!split)
        ft_error("Split Eroor");
    free(args);
    check_min_max(word_count, split);
    check_args_is_valid(split);
    res.array = (int *)malloc(sizeof(int) * word_count);
    if (!res.array)
    {
        ft_error("malloc Error");
        exit(1);
    }
    res.count = 0;
    while (res.count < word_count)
    {
        res.array[res.count] = at_oi(split[res.count]);
        res.count++;
    }
    ft_free(split);
    return (res);
}
t_stack get_main_stack(t_data *data)
{
    t_stack stack_a;

    stack_a = get_stack(data->allarg);
    if (!check_duplicate(&stack_a))
    {
        free(stack_a.array);
        ft_error("Duplicate Error");
        exit(1);
    }
    return (stack_a);
}

void check_min_max(int counter, char **args)
{
    int     i;
    long    res;

    i = 0;
    while (i < counter && args)
    {
        res = at_oi(args[i]);
        if (res < INT_MIN || res > INT_MAX)
        {
            ft_free(args);
            ft_error("integer overflow");
        }
        i++;
    }
}

t_stack clone_stack(t_stack stack_a)
{
    t_stack stack;
    stack.array = malloc(sizeof(int) * stack_a.count);
    if (!stack.array)
        free(stack.array);
    stack.count = 0;
    return (stack);
}