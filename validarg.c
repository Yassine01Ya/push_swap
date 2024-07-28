/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:53:10 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 01:48:06 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num(int i)
{
	if ((i >= '0' && i <= '9') || i == ' ' || i == '+' || i == '-')
		return (1);
	return (0);
}

int	check_signes(char *string)
{
	int	i;

	i = 0;
	if (string[0] == '+' || string[0] == '-')
		i++;
	if (!string[i])
		return (1);
	while (string[i] >= '0' && string[i] <= '9')
		i++;
	if (string[i])
		return (1);
	return (0);
}

int	check_validate(char *string)
{
	int	i;

	i = 0;
	if (!string || string[i] == '\0')
		return (0);
	while (string[i])
	{
		if (ft_num(string[i]) == 0)
			return (0);
		i++;
	}
	if (check_signes(string))
		return (0);
	return (1);
}

void	check_args_is_valid(char **args, t_data *data)
{
	int	i;

	i = 0;
	check_min_max(data, args);
	while (args[i] && args)
	{
		if (!check_validate(args[i]))
		{
			ft_free(args);
			free(data->allarg);
			ft_error();
		}
		i++;
	}
}

int	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->count - 1)
	{
		j = i + 1;
		while (j < stack->count)
		{
			if (stack->array[i] == stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
