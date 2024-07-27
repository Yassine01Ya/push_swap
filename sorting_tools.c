#include "push_swap.h"

int find_min(t_stack *stack)
{
    int i;
    int min;

    min = INT_MAX;
    i = 0;
    while (i < stack->count -1)
    {
        if (stack->array[i] < min)
            min = stack->array[i];
        i++;
    }
    return (min);
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

int find_p(int nb, int *array, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (nb == array[i])
            return (i);
        i++;
    }
    return (0);
}

int get_index(t_stack *stack, int num)
{
    int i;
    int index;

    index = 0;
    i = 0;
    while (i < stack->count - 1)
    {
        if (stack->array[i] == num)
            return (index);
        index++;
        i++;
    }
    return (-1);
}
int find_min_p(t_stack *stack)
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
void     bubble_sort(t_stack *stack)
{
    int tmp;
    int i;
    
    i = 0;
    while(i < stack->count - 1)
    {
        if (stack->array[i] > stack->array[i + 1])
        {
            tmp = stack->array[i];
            stack->array[i] = stack->array[i + 1];
            stack->array[i + 1] = tmp;
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