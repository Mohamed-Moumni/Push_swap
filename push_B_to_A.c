#include "push_swap.h"

void    index_stack(t_stack **stack)
{
    t_stack *tmp_stack;
    int     i;

    i = 0;
    tmp_stack = *stack;
    while (tmp_stack)
    {
        tmp_stack->index = i;
        tmp_stack->prev = i;
        tmp_stack->length = 0;
        i++;
        tmp_stack = tmp_stack->next;
    }
}

void    elem_pos(t_stack **s_a, t_stack *elem, t_size *size)
{
    t_stack *tmp_stack;
    t_stack *head;

    tmp_stack = *s_a;
    head = *s_a;
    while (tmp_stack->next)
    {
        if ((elem->number > tmp_stack->number && elem->number < tmp_stack->next->number))
        {
            elem->prev = elem->index;
            elem->lis = tmp_stack->next->index;
            return ;
        }
        tmp_stack = tmp_stack->next;
    }
    if (elem->number < head->number && elem->number > tmp_stack->number)
    {
        elem->prev = elem->index;
        elem->lis = head->index;
    }
    else
    {
        elem->prev = elem->index;
        tmp_stack = min_elem(*s_a, size->size);
        elem->lis = tmp_stack->index;
    }
}

void    move_to_top(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem)
{
    int middle;
    int middle2;

    middle = ((*stack_size)->size / 2);
    middle2 = ((*stack_size2)->size / 2);
    if ((b_elem->index > middle2 && b_elem->lis > middle) || (b_elem->index <= middle2 && b_elem->lis <= middle))
        double_or_riple_r(stack_a, stack_b, stack_size, stack_size2, b_elem);
    else
        normal_moves(stack_a, stack_b, stack_size, stack_size2, b_elem);
    // printf("-----------------------------\n");
    // printf("cont{%d} index{%d} -> [%d]\n", b_elem->number, b_elem->index, b_elem->lis);
    // printf("-----------------------------\n");
}

void    normal_moves(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem)
{
    int middle;
    int middle2;
    int move;

    middle = ((*stack_size)->size / 2);
    middle2 = ((*stack_size2)->size / 2);
    if (b_elem->index > middle2)
    {
        move = (*stack_size2)->size - (b_elem->index + 1) + 1;
        while (move--)
            ft_reverse_rotate_b(stack_b,stack_size2);
    }
    else
    {
        move = b_elem->index;
        while ( move != 0)
        {
            ft_rotate_b(stack_b, stack_size2);
            move--;
        }
    }
    if (b_elem->lis > middle)
    {
        move = (*stack_size)->size - (b_elem->lis + 1) + 1;
        while (move--)
            ft_reverse_rotate_a(stack_a, stack_size);
    }
    else
    {
        move = b_elem->lis;
        while (move != 0)
        {
            ft_rotate_a(stack_a, stack_size);
            move--;
        }
    }
}

void    double_or_riple_r(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem)
{
    int middle;
    int middle2;
    int moves;

    middle = ((*stack_size)->size / 2);
    middle2 = ((*stack_size2)->size / 2);
    if (b_elem->index <= middle2)
    {
        if (b_elem->index >= b_elem->lis)
        {
            moves = b_elem->lis;
            while (moves--)
                ft_rr(stack_a, stack_b, stack_size, stack_size2);
            moves = b_elem->index - b_elem->lis;
            while (moves--)
                ft_rotate_b(stack_b, stack_size2);
        }
        else
        {
            moves = b_elem->index;
            while (moves--)
                ft_rr(stack_a, stack_b, stack_size, stack_size2);
            moves = b_elem->lis - b_elem->index;
            while (moves--)
                ft_rotate_a(stack_a, stack_size);
        }
    }
    else
    {
        if (b_elem->index >= b_elem->lis)
        {
            moves = (*stack_size2)->size - (b_elem->index + 1) + 1;
            while (moves--)
                ft_rrr(stack_a, stack_b, stack_size, stack_size2);
            moves = b_elem->index - b_elem->lis;
            while (moves--)
                ft_reverse_rotate_a(stack_a, stack_size);
        }
        else
        {
            moves = (*stack_size)->size - (b_elem->lis + 1) + 1;
            while (moves--)
                ft_rrr(stack_a, stack_b, stack_size, stack_size2);
            moves = b_elem->lis - b_elem->index;
            while (moves--)
                ft_reverse_rotate_b(stack_b, stack_size2);
        }
    }
}