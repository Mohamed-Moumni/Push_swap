#include "push_swap.h"

void    b_top(t_stack **sa, t_stack *sb, int number)
{
    t_stack *tmp_stack;
    int     i;

    i = 0;
    tmp_stack = (*sa);
    while (tmp_stack)
    {
        if (tmp_stack->number == number)
        {
            sb->length = i;
            return ;
        }
        i++;
        tmp_stack = tmp_stack->next;
    }
}

void    best_elem(t_stack **sa, t_stack **sb)
{
    t_stack *tmp_stack;
    int     j;

    j = 0;
    tmp_stack = *sb;
    while (tmp_stack)
    {
        tmp_stack->prev = j;
        b_top(sa, tmp_stack, tmp_stack->number);
        j++;
        tmp_stack = tmp_stack->next;
    }
}

