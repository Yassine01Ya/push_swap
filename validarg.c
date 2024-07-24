#include "push_swap.h"
int ft_num(int i)
{
    if((i >= '0'&& i <= '9') || i == ' ' || i == '+' || i == '-')
        return 1;
    return 0;
}
int check_signes(char *string)
{
    int i;

    i = 0;
    if(string[0] == '+' || string[0] == '-')
        i++;
    if (!string[i])
        return 1;
    while (string[i] >= '0' && string[i] <= '9')
        i++;
    if (string[i])
        return 1;
    return 0;
}
int check_validate(char *string)
{
    int i;
    
    i = 0;
    if(!string || string[i] == '\0')
        return 0;
    while (string[i])
    {
        if (ft_num(string[i]) == 0)
            return 0;
        i++;
    }
    if (check_signes(string))
        // printf("hna");
            return 0;
    return 1;
}

void    check_args_is_valid(char **args)
{
    int i;

    i = 1;
    while (args[i] && args)
    {
        if (!check_validate(args[i]))
        {
            // printf("11111111111111111111111111111\n");
            ft_error("Invalid Argument");
            // printf("Invalid Argument\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }

}
