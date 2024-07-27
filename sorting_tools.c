#include "push_swap.h"

void find_min(t_stack *stack)
{
    int i;
    i = 0;
    stack->min = INT_MAX;

    while (i < stack->count)
    {
        if (stack->array[i] < stack->min)
            stack->min = stack->array[i];
        i++;
    }
}

int find_max(t_stack *stack)
{
    int i;
    int max;

    max = INT_MIN;
    i = 0;
    while (i <= stack->count -1)
    {
        if (stack->array[i] > max)
            max = stack->array[i];
        i++;
    }
    return (max);
}

int find_min_p(t_stack *stack)
{
    int index;

    index = 0;
    while (index < stack->count - 1)
    {
        if (stack->min == stack->array[index])
            return (index);
        index++;
    }
    return (index);
}

int find_max_p(t_stack *stack)
{
    int i;
    int index;

    index = 0;
    i = 0;
    while (i < stack->count - 1)
    {
        if (stack->min == stack->array[i])
            return (index);
        i++;
        index++;
    }
    return (index);
}
void     bubble_sort(t_holder *holder)
{
    int tmp;
    int i;
    
    i = 0;
    while(i < holder->count - 1)
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

int stack_is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while(i < stack->count - 1)
    {
        if (stack->array[i] > stack->array[i + 1])
                return (1);
        i++;
    }
    return (0);
}

t_holder    make_holder(t_stack *stack_a)
{
    t_holder holder;
    int i;

    holder.count = stack_a->count;
    i = 0;
    holder.sorted = malloc (sizeof (int) * stack_a->count);
        //malloc error to-do
    while (i < stack_a->count)
    {
        holder.sorted[i] = stack_a->array[i];
        i++;
    }
    bubble_sort(&holder);
    return (holder);
}