/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:55:41 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 01:29:53 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_big_sorting(t_holder holder, t_stack *stack_a, t_stack *stack_b,
		int range)
{
	int	len;
	int	i;

	i = 0;
	len = stack_a->count;
	while (i < len)
	{
		if (get_sorted_index(holder, stack_a->array[0]) <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (get_sorted_index(holder, stack_a->array[0]) <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (find_index(stack_a, holder, i, range) < stack_a->count / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	big_sorting(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_holder	holder;

	holder = make_holder(stack_a);
	start_big_sorting(holder, stack_a, stack_b, range);
	free(holder.sorted);
	push_to_stack_a(stack_a, stack_b);
}

void	push_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_posintion;

	while (stack_b->count)
	{
		max_posintion = find_max_p(stack_b);
		if (max_posintion <= stack_b->count / 2)
		{
			while (max_posintion > 0)
			{
				rb(stack_b);
				max_posintion--;
			}
		}
		else
		{
			max_posintion = stack_b->count - max_posintion;
			while (max_posintion > 0)
			{
				rrb(stack_b);
				max_posintion--;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	bubble_sort(t_holder *holder)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < holder->count - 1)
	{
		if (holder->sorted[i] > holder->sorted[i + 1])
		{
			tmp = holder->sorted[i];
			holder->sorted[i] = holder->sorted[i + 1];
			holder->sorted[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
