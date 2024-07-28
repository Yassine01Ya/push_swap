/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:52:49 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 00:52:50 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	find_min(stack_b);
	find_max(stack_b);
	find_min(stack_a);
	find_max(stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	find_min(stack_b);
	find_max(stack_b);
	find_min(stack_a);
	find_max(stack_a);
	write(1, "pb\n", 3);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a->array);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b->array);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a->array);
	swap(stack_b->array);
	write(1, "ss\n", 3);
}
