#include "push_swap.h"

int main (int c, char **v)
{
	t_data data;
	t_stack stack_a;

	get_args(&data, c, v);
	stack_a = get_main_stack(&data);
	int i = 0;
	while (i < stack_a.count)
	{
		printf("%d\n", stack_a.array[i]);
		i++;
	}
}