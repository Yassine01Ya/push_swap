/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:53:08 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 01:04:48 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	str_cat(char *string1, char *string2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string1 && string1[i])
		i++;
	while (string2[j])
	{
		string1[i] = string2[j];
		i++;
		j++;
	}
	string1[i] = '\0';
}

long	at_oi(char *s)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (neg * res);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
