#include "push_swap.h"

void    index_stack(t_stack **stack, t_size *size)
{
    t_stack *tmp_stack;
    int     i;
    int     j;

    i = 0;
    j = 0;
    tmp_stack = *stack;
    while (tmp_stack)
    {
        if (i < size->size / 2)
        {
            tmp_stack->index = i;
        }
        else
        {
            tmp_stack->index = --j;
        }
        i++;
        tmp_stack = tmp_stack->next;
    }
}

int elem_pos(t_stack **s_a, t_stack *elem, t_size *size)
{
    // t_stack *tmp_stack;
    t_stack *last_elm;

    last_elm = ft_last_elem(*s_a);
    if (elem->number > last_elm->number && elem->number < (*s_a)->number)
    {
        elem->prev = elem->index;
        elem->lis = last_elm->index;
        return (1);
    }
    else if (is_in_top_half(*s_a, elem, size))
        return (2);
    else if (is_in_bottom_half(*s_a, elem, size))
        return (3);
    else
        return (4);
}

int is_in_top_half(t_stack *s_a, t_stack *elem,t_size *size)
{
    int     i;
    t_stack *tmp_stack;

    i = 0;
    tmp_stack = s_a;
    while (i < size->size / 2)
    {
        if (elem->number > tmp_stack->number &&
            elem->number < tmp_stack->next->number)
            {
                elem->prev = elem->index;
                elem->lis = tmp_stack->index;
                return (1);
            }
        i++;
    }
    return (0);
}
// there is more to do with this function//
int is_in_bottom_half(t_stack *s_a, t_stack *elem,t_size *size)
{
    int     i;
    t_stack *tmp_stack;

    i = 0;
    tmp_stack = s_a;
    while (i < size->size / 2)
    {
        i++;
        tmp_stack = tmp_stack->next;
    }
    while (i < size->size - 1)
    {
        if (elem->number > tmp_stack->number &&
            elem->number < tmp_stack->next->number)
            {
                elem->prev = elem->index;
                elem->lis = tmp_stack->index;
                return (1);
            }
        i++;
    }
    return (0);
}

