/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:37:31 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/15 20:32:26 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_in_top(t_stack **stack, t_info *info)
{
	t_stack	*min_number;
	int		min;
	int		middle;

	min_number = min_elem(*stack);
	min = min_number->index;
	middle = info->size_a / 2;
	if (min > middle)
		while ((*stack)->number != min_number->number)
			ft_reverse_rotate(stack, "rra\n", info);
	else
		while ((*stack)->number != min_number->number)
			ft_rotate(stack, "ra\n", info);
}

t_stack	*min_elem(t_stack *stack)
{
	t_stack	*tmp_stack;
	t_stack	*minimum;
	int		min;

	min = max_of_stack(stack)->number;
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

void	index_stack(t_stack **stack)
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
