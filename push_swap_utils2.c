#include "push_swap.h"

int min_stack(t_stack *stack, int size)
{
    t_stack *tmp_stack;
    int      min;
    int     count;
    int     min_pos;

    count = 0;
    min_pos = 1;
    min = stack->number;
    tmp_stack = stack->next;;
    while (min_pos < size)
    {
        min_pos++;
        if (tmp_stack->number <= min)
        {
            min = tmp_stack->number;
            count = min_pos;
        }
        tmp_stack = tmp_stack->next;
    }
    return (count);
}