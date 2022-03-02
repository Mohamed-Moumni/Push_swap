#include "push_swap.h"

int min_num(int a, int b)
{
    if (a < b)
        return(a);
    return (b);
}

int ft_abs(int a)
{
    if (a < 0)
        return (-a);
    return(a);
}
void    sort_all(t_stack **s_a ,t_stack **s_b, t_size *size, t_size *size2)
{
    t_stack *tmp_stack;
    int     move;

    tmp_stack = *s_b;
    while (tmp_stack)
    {
        move = elem_pos(s_a, tmp_stack, size);
        best_elem(tmp_stack, move);
        tmp_stack = tmp_stack->next;
    }
}
void    sort(t_stack **stack_a, t_stack **stack_b, t_stack *tmp_stack,t_size **stack_size, t_size **stack_size2)
{
    int min;
    int diff;

    if (tmp_stack->prev < 0 && tmp_stack->lis < 0)
    {
        min = min_num(ft_abs(tmp_stack->prev), ft_abs(tmp_stack->lis));
        while (min--)
            ft_rrr(stack_a, stack_b, stack_size, stack_size2);
        diff = ft_abs(tmp_stack->prev) - ft_abs(tmp_stack->lis);
        if (diff > 0)
        {
            while (diff--)
            {
                ft_reverse_rotate_b(stack_b,stack_size2);
            }
        }
        else
        {
            while (++diff)
            {
                ft_reverse_rotate_a(stack_a,stack_size);
            }
        }
    }
    else if (tmp_stack->prev > 0 && tmp_stack->lis > 0)
    {
        min = min_num(ft_abs(tmp_stack->prev), ft_abs(tmp_stack->lis));
        while (min--)
            ft_rr(stack_a, stack_b, stack_size, stack_size2);
        diff = ft_abs(tmp_stack->prev) - ft_abs(tmp_stack->lis);
        if (diff > 0)
        {
            while (diff--)
            {
                ft_rotate_b(stack_b,stack_size2);
            }
        }
        else
        {
            while (++diff)
            {
                ft_rotate_a(stack_a,stack_size);
            }
        }   
    }
    else
    {
    }
}

void    best_move(t_stack *b_elem, int move)
{
    if (move == 1)
        (b_elem)->length = ft_abs(b_elem->lis);
    else if(move == 2)
        (b_elem)->length = min_num(b_elem->prev, b_elem->lis) + ft_abs(b_elem->lis) - ft_abs(b_elem->prev);
    else if (move == 3)
        (b_elem)->length = min_num(b_elem->prev, b_elem->lis) + ft_abs(b_elem->lis) - ft_abs(b_elem->prev);
    else
        (b_elem)->length = ft_abs(b_elem->lis);       
}

t_stack *min_move(t_stack **stack_b)
{
    t_stack *tmp_stack;
    int     min;
    t_stack *min_stack;

    tmp_stack = *stack_b;
    min = tmp_stack->length; 
    while (tmp_stack)
    {
        if (min >= tmp_stack->length)
        {
            min_stack = tmp_stack;
            min = tmp_stack->length;
        }
        tmp_stack = tmp_stack->next;
    }
    return (min_stack);
}
void    B_to_A(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    t_stack *tmp_stack;

    while ((*stack_size2)->size != 0)
    {
        sort_all(stack_a, stack_b, &stack_size , &stack_size2);
        tmp_stack = min_move(stack_b);
        sort(stack_a, tmp_stack, stack_size, stack_size2);
    }
}