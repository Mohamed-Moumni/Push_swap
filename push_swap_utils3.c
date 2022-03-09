/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:37:31 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/09 19:14:54 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (tmp_stack != NULL)
	{
		// printf("%d\n", tmp_stack->number);
		printf("elem[%d] index[%d] lis[%d] lis_len[%d] prev[%d] dis[%d]\n", tmp_stack->number, tmp_stack->index, tmp_stack->lis, tmp_stack->lis_len, tmp_stack->prev, tmp_stack->dis);
		tmp_stack = tmp_stack->next;
	}
}

void	min_in_top(t_stack **stack, t_info *info)
{
	t_stack	*tmp_stack;
	int		min;
	int		middle;
	
    tmp_stack = min_elem(*stack, info->size_a);
    min = tmp_stack->index;
    middle = info->size_a / 2;
    if (min > middle)
    {
        min = info->size_a - (tmp_stack->index + 1) + 1;
        while (min--)
            ft_reverse_rotate(stack, "rra\n", info);
    }
    else
    {
        while (min--)
            ft_rotate(stack, "ra\n", info);
    }
}

t_stack	*min_elem(t_stack *stack, int size)
{
    t_stack *tmp_stack;
    t_stack *minimum;
	
    tmp_stack = stack;
    minimum = stack;
    while (tmp_stack)
    {
        if (tmp_stack->number <= minimum->number)
        {
            minimum = tmp_stack;
        }
        tmp_stack = tmp_stack->next;
    }
    return (minimum);
}