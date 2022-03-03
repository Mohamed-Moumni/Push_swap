#include "push_swap.h"


t_stack *max_of_length(t_stack **stack)
{
    int     max;
    t_stack *tmp_stack;
    t_stack *max_elem;

    tmp_stack = *stack;
    max = 0;
    while (tmp_stack)
    {
        if (tmp_stack->length  >= max)
        {
            max = tmp_stack->length;
            max_elem = tmp_stack;
        }
        tmp_stack = tmp_stack->next;
    }
    return (max_elem);
}

t_stack *find_elem_by_index(t_stack **stack, int prev)
{
    t_stack *tmp_stack;

    tmp_stack = *stack;
    while (tmp_stack)
    {
        if (tmp_stack->index == prev)
        {
            return (tmp_stack);
        }
        tmp_stack = tmp_stack->next;
    }
    return (NULL);
}

void    get_LIS(t_stack **stack, t_size **stack_size)
{
    t_stack *tmp_stack;
    int     index;
    int max;

    tmp_stack = max_of_length(stack);
    tmp_stack->lis = 1;
    max = tmp_stack->length;
    index = tmp_stack->prev;
    max--;
    while (max > 0)
    {
        tmp_stack = find_elem_by_index(stack, index);
        tmp_stack->lis = 1;
        index = tmp_stack->prev;
        max--;
    }
    tmp_stack = min_elem(*stack, (*stack_size)->size);
    printf("%d\n", tmp_stack->number);
    tmp_stack->lis = 1;
}


void    LIS_in_stack(t_stack **stack, int size)
{
    t_stack *tmp_stack1;
    t_stack *tmp_stack2;
    int     i;
    int     j;

    i = 0;
    tmp_stack1 = *stack;
    while (i < size)
    {
        j = 0;
        tmp_stack2 = *stack;
        while (j < i)
        {
            if (tmp_stack2->number < tmp_stack1->number &&
                tmp_stack1->length <= tmp_stack2->length + 1)
            {
                tmp_stack1->length = tmp_stack2->length + 1;
                tmp_stack1->prev = j;
            }
            tmp_stack2 = tmp_stack2->next;
            j++;
        }
        tmp_stack1 = tmp_stack1->next;
        i++;
    }
}