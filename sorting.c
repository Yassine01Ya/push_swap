#include "push_swap.h"

void sort_3(t_stack *stack)
{

    find_max(stack);
    if (stack->max == stack->array[0])
        ra(stack);
    else if (stack->max == stack->array[1])
        rra(stack);
    if (stack_is_sorted(stack))
        sa(stack);
}

void sort_5(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int index;

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

int ft_cap(int val, int min, int max)
{
    if (val < min)
        return min;
    if (val > max)
        return max;
    return val;
}

int get_sorted_index(t_holder holder, int val)
{
    int i;

    i = 0;
    while (i < holder.count)
    {
        if (holder.sorted[i] == val)
            return i;
        i++;
    }
    return -1;
}

int find_index(t_stack *a, t_holder holder, int index, int range)
{
    int i;

    i = 0;
    while (i < a->count)
    {
        if (get_sorted_index(holder, a->array[i]) <= index || get_sorted_index(holder, a->array[i]) <= index + range)
            break;
        i++;
    }
    return (i);
}

void start_big_sorting(t_holder holder, t_stack *stack_a, t_stack *stack_b, int range)
{
    int len;
    int i;

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

void big_sorting(t_stack *stack_a, t_stack *stack_b, int range)
{
    t_holder holder;

    holder = make_holder(stack_a);
    start_big_sorting(holder, stack_a, stack_b, range);
    free(holder.sorted);
    push_to_stack_a(stack_a, stack_b);
}

void push_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    int max_posintion;

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