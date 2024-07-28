/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:52:58 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 01:10:58 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_stack *stack)
{
	int	i;

	i = 0;
	stack->min = INT_MAX;
	while (i < stack->count)
	{
		if (stack->array[i] < stack->min)
			stack->min = stack->array[i];
		i++;
	}
}

void	find_max(t_stack *stack)
{
	int	i;

	i = 0;
	stack->max = INT_MIN;
	while (i < stack->count)
	{
		if (stack->array[i] > stack->max)
			stack->max = stack->array[i];
		i++;
	}
}

int	find_min_p(t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->count)
	{
		if (stack->min == stack->array[index])
			return (index);
		index++;
	}
	return (index);
}

int	find_max_p(t_stack *stack)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (i < stack->count)
	{
		if (stack->max == stack->array[i])
			return (index);
		i++;
		index++;
	}
	return (index);
}

t_holder	make_holder(t_stack *stack_a)
{
	t_holder	holder;
	int			i;

	holder.count = stack_a->count;
	i = 0;
	holder.sorted = malloc(sizeof(int) * stack_a->count);
	if (!holder.sorted)
		exit(EXIT_FAILURE);
	while (i < stack_a->count)
	{
		holder.sorted[i] = stack_a->array[i];
		i++;
	}
	bubble_sort(&holder);
	return (holder);
}
