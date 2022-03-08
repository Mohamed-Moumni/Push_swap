/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_sub.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:16:56 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/08 21:37:24 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_of_length(t_stack **stack)
{
	int		max;
	t_stack	*tmp_stack;
	t_stack	*max_elem;

	tmp_stack = *stack;
	max = 0;
	while (tmp_stack)
	{
		if (tmp_stack->length > max)
		{
			max = tmp_stack->length;
			max_elem = tmp_stack;
		}
		tmp_stack = tmp_stack->next;
	}
	return (max_elem);
}

t_stack	*find_elem_by_index(t_stack **stack, int prev)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	while (tmp_stack)
	{
		if (tmp_stack->index == prev)
			return (tmp_stack);
		tmp_stack = tmp_stack->next;
	}
	return (NULL);
}

void	get_lis(t_stack **stack, t_size **stack_size)
{
	t_stack	*tmp_stack;
	int		index;
	int		max;

	tmp_stack = max_of_length(stack);
	tmp_stack->lis = 1;
	index = tmp_stack->prev;
	while (index != -1)
	{
		tmp_stack = find_elem_by_index(stack, index);
		tmp_stack->lis = 1;
		index = tmp_stack->prev;
	}
}

void    find_lis(t_stack **stack)
{
    t_stack *tmp_i;
    t_stack	*tmp_j;

    tmp_i = (*stack)->next;
    while (tmp_i != NULL)
    {
        tmp_j = *stack;
        while (tmp_j != tmp_i)
        {
            if (tmp_i->number > tmp_j->number)
            {
				tmp_i->length = max(tmp_i->length, tmp_j->length + 1);
                if (tmp_i->length <= tmp_j->length + 1)
                    tmp_i->prev = tmp_j->index;
            }
            tmp_j = tmp_j->next;
        }
        tmp_i = tmp_i->next;
    }
}
