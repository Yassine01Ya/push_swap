/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:53:06 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 22:11:06 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count == 3)
		sort_3(stack_a);
	else if (stack_a->count <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->count <= 200)
		big_sorting(stack_a, stack_b, 15);
	else
		big_sorting(stack_a, stack_b, 30);
}

int	main(int c, char **v)
{
	t_data	data;
	t_stack	stack_a;
	t_stack	stack_b;

	get_args(&data, c, v);
	stack_a = get_main_stack(&data);
	if (stack_a.array == NULL)
		return (EXIT_FAILURE);
	if (stack_is_sorted(&stack_a) == 0)
	{
		free(stack_a.array);
		return (EXIT_FAILURE);
	}
	stack_b = clone_stack(stack_a);
	if (stack_b.array == NULL)
	{
		free(stack_a.array);
		return (EXIT_FAILURE);
	}
	sort_stacks(&stack_a, &stack_b);
	free(stack_a.array);
	free(stack_b.array);
}
