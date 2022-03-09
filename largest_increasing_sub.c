/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_sub.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:16:56 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/09 17:33:56 by mmoumni          ###   ########.fr       */
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
		if (tmp_stack->lis_len > max)
		{
			max = tmp_stack->lis_len;
			max_elem = tmp_stack;
		}
		tmp_stack = tmp_stack->next;
	}
	return (max_elem);
}

t_stack	*find_elem_by_index(t_stack **stack, int index)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	while (tmp_stack)
	{
		if (tmp_stack->index == index)
			return (tmp_stack);
		tmp_stack = tmp_stack->next;
	}
	return (NULL);
}

void	get_lis(t_stack **stack)
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

void	find_lis(t_stack **stack)
{
	t_stack	*tmp_i;
	t_stack	*tmp_j;

	tmp_i = (*stack)->next;
	while (tmp_i != NULL)
	{
		tmp_j = *stack;
		while (tmp_j != tmp_i)
		{
			if (tmp_i->number > tmp_j->number)
			{
				tmp_i->lis_len = ft_max(tmp_i->lis_len, tmp_j->lis_len + 1);
				if (tmp_i->lis_len <= tmp_j->lis_len + 1)
					tmp_i->prev = tmp_j->index;
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}
