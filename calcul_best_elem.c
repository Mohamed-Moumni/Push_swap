/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_best_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:33 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 18:13:00 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_best_elem(t_stack *b_elem, t_info *info)
{
	int	middle_a;
	int	middle_b;
	int	a;
	int	b;

	middle_a = info->size_a / 2;
	middle_b = info->size_b / 2;
	if ((b_elem->index > middle_b && b_elem->pair > middle_a)
		|| (b_elem->index <= middle_b && b_elem->pair <= middle_a))
	{
		a = info->size_b - (b_elem->index + 1);
		b = info->size_a - (b_elem->pair + 1);
		if ((b_elem->index > middle_b && b_elem->pair > middle_a))
			b_elem->dis = ft_max(a, b);
		else
			b_elem->dis = ft_max(b_elem->index, b_elem->pair);
	}
	else
		b_elem->dis = calcul_moves(b_elem, info);
}

int	calcul_moves(t_stack *b_elem, t_info *info)
{
	int	moves;
	int	middle_a;
	int	middle_b;

	middle_a = info->size_a / 2;
	middle_b = info->size_b / 2;
	moves = 0;
	if (b_elem->index <= middle_b)
		moves += b_elem->index;
	else
		moves += info->size_b - (b_elem->index + 1);
	if (b_elem->pair <= middle_a)
		moves += b_elem->pair;
	else
		moves += info->size_a - (b_elem->pair + 1);
	return (moves);
}

void	marking_best_elem(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack_b;
	while (tmp_stack)
	{
		elem_pos(stack_a, tmp_stack);
		calculate_best_elem(tmp_stack, info);
		tmp_stack = tmp_stack->next;
	}
}

t_stack	*min_move(t_stack **stack_b, t_info *info)
{
	t_stack	*tmp_stack;
	int		min;
	t_stack	*min_stack;

	tmp_stack = *stack_b;
	min = info->size_a + info->size_b;
	while (tmp_stack)
	{
		if (min > tmp_stack->dis)
		{
			min_stack = tmp_stack;
			min = tmp_stack->dis;
		}
		tmp_stack = tmp_stack->next;
	}
	return (min_stack);
}

void	b_to_a(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	t_stack	*tmp_stack;

	tmp_stack = NULL;
	while ((*stack_b))
	{
		index_stack(stack_a);
		index_stack(stack_b);
		marking_best_elem(stack_a, stack_b, info);
		tmp_stack = min_move(stack_b, info);
		mv_to_top(stack_a, stack_b, tmp_stack, info);
		ft_push(stack_b, stack_a, "pa\n");
		info->size_a += 1;
		info->size_b -= 1;
	}
}
