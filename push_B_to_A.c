/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_B_to_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:15 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/08 21:37:31 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int value1, int value2)
{
    if (value1 > value2)
        return (value2);
    return (value1);
}

void    index_stack(t_stack **stack)
{
    t_stack *tmp_stack;
    int     i;

    i = 0;
    tmp_stack = *stack;
    while (tmp_stack)
    {
        tmp_stack->index = i;
        tmp_stack->length = 0;
        tmp_stack->lis = 0;
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
            elem->lis = tmp_stack->next->index;
            return ;
        }
        tmp_stack = tmp_stack->next;
    }
    if (elem->number < head->number && elem->number > tmp_stack->number)
        elem->lis = head->index;
    else
    {
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
}

void    normal_moves(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem)
{
    int middle;
    int middle2;
    t_stack *a_elem;

    middle = ((*stack_size)->size / 2);
    middle2 = ((*stack_size2)->size / 2);
    a_elem = find_elem_by_index(stack_a, b_elem->lis);
    if (b_elem->index > middle2)
    {
        while ((*stack_b)->number != b_elem->number)
            ft_reverse_rotate_b(stack_b,stack_size2);
    }
    else
    {
        while ((*stack_b)->number != b_elem->number)
            ft_rotate_b(stack_b, stack_size2);
    }
    if (b_elem->lis > middle)
    {
        while ((*stack_a)->number != a_elem->number)
            ft_reverse_rotate_a(stack_a, stack_size);
    }
    else
    {
        while ((*stack_a)->number != a_elem->number)
        {
            ft_rotate_a(stack_a, stack_size);
        }
    }
}

void    double_or_riple_r(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem)
{
    int middle;
    int middle2;
    int moves;
    t_stack *a_elem;

    a_elem = find_elem_by_index(stack_a, b_elem->lis);
    middle = ((*stack_size)->size / 2);
    middle2 = ((*stack_size2)->size / 2);
    if (b_elem->index <= middle2)
    {
        while ((*stack_a)->number != a_elem->number && (*stack_b)->number != b_elem->number)
            ft_rr(stack_a, stack_b, stack_size, stack_size2);
        while ((*stack_a)->number != a_elem->number)
            ft_rotate_a(stack_a, stack_size);
        while ((*stack_b)->number != b_elem->number)
            ft_rotate_b(stack_b, stack_size2);
    }
    else
    {
        while ((*stack_a)->number != a_elem->number && (*stack_b)->number != b_elem->number)
            ft_rrr(stack_a, stack_b, stack_size, stack_size2);
        while ((*stack_a)->number != a_elem->number)
            ft_reverse_rotate_a(stack_a, stack_size);
        while ((*stack_b)->number != b_elem->number)
            ft_reverse_rotate_b(stack_b, stack_size2);
    }
}