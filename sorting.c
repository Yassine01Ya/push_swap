#include "push_swap.h"

void    sort_3(t_stack *stack)
{

    stack->max = find_max(stack);
    if (stack->max == stack->array[0])
        ra(stack);
    else if (stack->max == stack->array[1])
        rra(stack);
    if (stack_is_sorted(stack))
        sa(stack);
}

void    sort_5(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int index;

    stack_a->min = find_min(stack_a);
    index = find_min_p(stack_a);
    size = stack_a->count;
    while (stack_a->count > 3)
    {
        if (index == 0)
            pb(stack_a, stack_b);
        else if (index <= size / 2)
            ra(stack_a);
        else if (index > size / 2)
            rra(stack_a);
        stack_a->min = find_min(stack_a);
        index = find_min_p(stack_a);
        size = stack_a->count;
    }
    sort_3(stack_a);
    while (stack_b->count > 0)
        pa(stack_a, stack_b);
}