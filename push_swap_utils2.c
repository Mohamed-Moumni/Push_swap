/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:37:31 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/11 19:50:05 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_in_top(t_stack **stack, t_info *info)
{
	t_stack	*tmp_stack;
	int		min;
	int		middle;

	tmp_stack = min_elem(*stack, info);
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

t_stack	*min_elem(t_stack *stack, t_info *info)
{
	t_stack	*tmp_stack;
	t_stack	*minimum;
	int		min;

	min = info->size_a + info->size_b;
	tmp_stack = stack;
	minimum = stack;
	while (tmp_stack)
	{
		if (tmp_stack->number < min)
		{
			minimum = tmp_stack;
			min = tmp_stack->number;
		}
		tmp_stack = tmp_stack->next;
	}
	return (minimum);
}

int	ft_min(int value1, int value2)
{
	if (value1 > value2)
		return (value2);
	return (value1);
}

void	index_stack(t_stack **stack, t_info *info)
{
	t_stack	*tmp_stack;
	int		i;

	i = 0;
	tmp_stack = *stack;
	while (tmp_stack)
	{
		tmp_stack->index = i;
		tmp_stack = tmp_stack->next;
		i++;
	}
}
