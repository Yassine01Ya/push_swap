#include "push_swap.h"

int main (int c, char **v)
{
	t_data data;
	t_stack stack_a;
	t_stack stack_b;

	get_args(&data, c, v);
	stack_a = get_main_stack(&data);
	if (stack_is_sorted(&stack_a) == 0)
	{	
		free(stack_a.array);
		exit(1);
	}
	stack_b = clone_stack(stack_a);
	int i = 0;
	if (stack_a.count == 3)
		sort_3(&stack_a);
	else if (stack_a.count<= 5)
		sort_5(&stack_a, &stack_b);
	while (i < stack_a.count)
	{
		printf("%d\n", stack_a.array[i]);
		i++;
	}
}