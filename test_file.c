int	ft_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[i] == '\0')
		return (0);
	while (arg && arg[i] != 0)
	{
		if (ft_num(arg[i]) == 0)
			return (0);
		i++;
	}
	if (checck_signs(a))
		return (0);
	return (1);
}

int main()
{
    char *string = "12";
    printf("%d\n", check_validate(string));
}