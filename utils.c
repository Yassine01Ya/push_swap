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
void    ft_error(char *arg)
{
    ft_putendl(arg, 2);
    exit(1);
}
void    ft_free(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[]);
        i++;
    }
    free(args);
}