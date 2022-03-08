/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:33 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/08 21:22:09 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

void     calculate_best_elem(t_stack *b_elem, t_size *size, t_size *size2)
{
    int middle;
    int middle2;
    int moves;
    int a;
    int b;

    middle = (size->size / 2);
    middle2 = (size2->size / 2);
    moves = 0;
    if (((b_elem->index > middle2 && b_elem->lis > middle) || (b_elem->index <= middle2 && b_elem->lis <= middle)))
    {
        a = (size)->size - (b_elem->index + 1) + 1;
        b = (size2)->size - (b_elem->lis + 1) + 1;
        if ((b_elem->index > middle2 && b_elem->lis > middle))
            b_elem->length = max(a, b);
        else
            b_elem->length = max(b_elem->index, b_elem->lis);
    }
    else
    {
        if (b_elem->index <= middle2)
            moves += b_elem->index;
        else
            moves += size2->size - (b_elem->index + 1) + 1;
        if (b_elem->lis <= middle)
            moves += b_elem->lis;
        else
            moves += size->size - (b_elem->lis + 1) + 1;
        b_elem->length = moves;
    }
}

void    sort_all(t_stack **s_a ,t_stack **s_b, t_size *size, t_size *size2)
{
    t_stack *tmp_stack;
    int     move;

    tmp_stack = *s_b;
    while (tmp_stack)
    {
        elem_pos(s_a, tmp_stack, size);
        calculate_best_elem(tmp_stack,size, size2);
        tmp_stack = tmp_stack->next;
    }
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
void    print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("ele[%d] index[%d] lis[%d] -> p_index[%d] (%d)\n",stack->number, stack->index, stack->lis, stack->prev, stack->length);
        stack = stack->next;
    }
}
void    B_to_A(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    t_stack *tmp_stack;
    int     move;
    while ((*stack_b))
    {
        index_stack(stack_a);
        index_stack(stack_b);
        // printf("-----------A-------------\n");
        // print_stack(*stack_a);
        // printf("-----------B-------------\n");
        // print_stack(*stack_b);
        // printf("-----------------------------\n");
        sort_all(stack_a, stack_b, *stack_size, *stack_size2);
        tmp_stack = min_move(stack_b);
        // printf("l9wada[%d]\n", tmp_stack->length);
        // printf("elem{%d} index{%d} | pair: {%d}\n",tmp_stack->number, tmp_stack->index, tmp_stack->lis);
        // printf("-----------------------------\n");
        move_to_top(stack_a, stack_b, stack_size, stack_size2, tmp_stack);
        ft_pa(stack_a, stack_b, stack_size, stack_size2);
    }
}