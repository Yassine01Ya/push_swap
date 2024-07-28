/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:53:01 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 00:56:23 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	find_max(stack);
	if (stack->max == stack->array[0])
		ra(stack);
	else if (stack->max == stack->array[1])
		rra(stack);
	if (stack_is_sorted(stack))
		sa(stack);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	index;

	while (stack_a->count > 3)
	{
		find_min(stack_a);
		index = find_min_p(stack_a);
		size = stack_a->count;
		if (index == 0)
			pb(stack_a, stack_b);
		else if (index <= size / 2)
			ra(stack_a);
		else if (index > size / 2)
			rra(stack_a);
	}
	sort_3(stack_a);
	while (stack_b->count > 0)
		pa(stack_a, stack_b);
}

int	ft_cap(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

int	get_sorted_index(t_holder holder, int val)
{
	int	i;

	i = 0;
	while (i < holder.count)
	{
		if (holder.sorted[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

int	find_index(t_stack *a, t_holder holder, int index, int range)
{
	int	i;

	i = 0;
	while (i < a->count)
	{
		if (get_sorted_index(holder, a->array[i]) <= index
			|| get_sorted_index(holder, a->array[i]) <= index + range)
			break ;
		i++;
	}
	return (i);
}
