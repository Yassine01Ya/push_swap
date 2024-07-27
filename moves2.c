#include "push_swap.h"
void    pa(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_b, stack_a);
    if (stack_b->count)
    {
        stack_a->count++;
        stack_b->count--;
    }
    write(1, "pa\n", 3);
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    if (stack_a->count)
    {
        stack_a->count--;
        stack_b->count++;
    }
    write(1, "pb\n", 3);
}

void    sa(t_stack *stack_a)
{
    swap(stack_a->array);
    write(1, "sa\n", 3);
}

void    sb(t_stack *stack_b)
{
    swap(stack_b->array);
    write(1, "sb\n", 3);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a->array);
    swap(stack_b->array);
    write(1, "ss\n", 3);
}