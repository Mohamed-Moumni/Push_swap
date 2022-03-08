/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/08 18:32:52 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    ft_swap_a(t_stack **stack) /// 3ndak swap
{
    int tmp;
    int tmp_next;

    tmp = (*stack)->number;
    tmp_next = (*stack)->next->number;
    (*stack)->next->number = tmp;
    (*stack)->number = tmp_next;
    write(1, "sa\n", 3);
}

void    ft_ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap_a(stack_a);
    ft_swap_b(stack_b);
    write(1, "ss\n", 3);
}

void ft_pa(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    int poped_elem;

    if (*stack_b == NULL)
        return ;
    poped_elem = 0;
    pop(stack_b, &poped_elem, stack_size2);
    push(stack_a, poped_elem, stack_size);
    write(1, "pa\n", 3);
}

t_stack *ft_last_elem(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return (tmp);
}

void ft_rotate_a(t_stack **stack, t_size **stack_size)
{
    int poped_elem;
    t_stack *bottom_stack;
    t_stack *node;

    poped_elem = 0;
    pop(stack, &poped_elem, stack_size);
    bottom_stack = ft_last_elem(*stack);
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->number = poped_elem;
    node->next = NULL;
    bottom_stack->next = node;
    (*stack_size)->size += 1;
    write(1, "ra\n", 3);
}

void ft_rotate_x(t_stack **stack, t_size **stack_size)
{
    int poped_elem;
    t_stack *bottom_stack;
    t_stack *node;

    poped_elem = 0;
    pop(stack, &poped_elem, stack_size);
    bottom_stack = ft_last_elem(*stack);
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->number = poped_elem;
    node->next = NULL;
    bottom_stack->next = node;
    (*stack_size)->size += 1;
}

void    ft_rr(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    ft_rotate_x(stack_a, stack_size);
    ft_rotate_x(stack_b, stack_size2);
    write(1, "rr\n", 3);
}

void    ft_reverse_rotate_a(t_stack **stack, t_size **stack_size)
{
    int poped_elem;
    t_stack *before_last;
    t_stack *node;

    before_last = (*stack);
    while ((before_last)->next->next != NULL)
    {
        before_last = before_last->next;
    }
    poped_elem = before_last->next->number;
    free(before_last->next);
    before_last->next = NULL;
    (*stack_size)->size -= 1;
    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return ;
    push(stack, poped_elem, stack_size);
    write(1, "rra\n", 4);
}

void    ft_reverse_rotate_x(t_stack **stack, t_size **stack_size)
{
    int poped_elem;
    t_stack *before_last;
    t_stack *node;

    before_last = (*stack);
    while ((before_last)->next->next != NULL)
    {
        before_last = before_last->next;
    }
    poped_elem = before_last->next->number;
    free(before_last->next);
    before_last->next = NULL;
    (*stack_size)->size -= 1;
    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return ;
    push(stack, poped_elem, stack_size);
}

void    ft_rrr(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    ft_reverse_rotate_x(stack_a, stack_size);
    ft_reverse_rotate_x(stack_b, stack_size2);
    write(1, "rrr\n", 4);
}
