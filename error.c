#include "push_swap.h"

void ft_putendl(char *string, int fd)
{
    int i;

    i = 0;
    if (!string || string[i] == '\0')
        return ;
    while (string[i])
    {
        write (fd, &string[i], 1);
        i++;
    }
}
void    ft_error()
{
  ft_putendl("Error", 2);
  exit(EXIT_FAILURE);
}
void    ft_free(char **args)
{
    int i;

    i = 0;
    while (args[i] != NULL)
    {
        free(args[i]);
        i++;
    }
    free(args);
    
}