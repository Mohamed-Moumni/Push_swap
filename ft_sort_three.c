#include"push_swap.h"

void ft_sort_three(t_stack **stack)
{
    t_stack *tmp_curr;
    t_stack *tmp_next;

    tmp_curr = *stack;
    tmp_next = (*stack)->next;
    if (tmp_curr->number < tmp_next->number)
    {
        if (tmp_next->next->number > tmp_curr->number)
            {
                ft_reverse_rotate_ab(stack);
                ft_swap_ab(stack);
            }
        else
            ft_reverse_rotate_ab(stack);
    }
    else if (tmp_next->number < tmp_curr->number && tmp_next->number < tmp_next->next->number)
    {
        if (tmp_curr->number < tmp_next->next->number)
            ft_swap_ab(stack);
        else
            ft_rotate_ab(stack);
    }
    else
    {
        ft_swap_ab(stack);
        ft_reverse_rotate_ab(stack);
    }
}