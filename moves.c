#include "push_swap.h"

void    swap(int *array)
{
    int tmp;

    tmp = array[0];
    array[0] = array[1];
    array[1] = tmp;
}

void    rotate(t_stack *stack)
{
    int i;
    int tmp;
    
    i = 0;
    tmp = stack->array[i];
    while (i < stack->count - 1)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[stack->count - 1] = tmp;
}

void    reverse_rotate(t_stack *stack)
{
    int i;
    int tmp;

    i = stack->count - 1;
    tmp = stack->array[i];
    while (stack->array && i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = tmp;
}

void    push(t_stack *stack1, t_stack *stack2)
{
    int i;
    int tmp;

    if (stack1->count == 0)
        return ;
    i = 0;
    tmp = stack1->array[0];
    while (i < stack1->count - 1)
    {
        stack1->array[i] = stack1->array[i + 1];
        i++;
    }
    stack1->count--;
    i = stack2->count;
    stack2->count++;
    while (i > 0)
    {
        stack2->array[i] = stack2->array[i - 1];
        i--;
    }
    stack2->array[0] = tmp;
}
