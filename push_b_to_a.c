/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:42:57 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/15 10:47:33 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elem_pos(t_stack **stack_a, t_stack *elem)
{
	t_stack	*tmp_stack;
	t_stack	*head;

	tmp_stack = *stack_a;
	head = *stack_a;
	while (tmp_stack->next)
	{
		if ((elem->number > tmp_stack->number)
			&& (elem->number < tmp_stack->next->number))
		{
			elem->pair = tmp_stack->next->index;
			return ;
		}
		tmp_stack = tmp_stack->next;
	}
	if (elem->number < head->number && elem->number > tmp_stack->number)
		elem->pair = head->index;
	else
	{
		tmp_stack = min_elem(*stack_a);
		elem->pair = tmp_stack->index;
	}
}

void	mv_to_top(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info)
{
	int	middle_a;
	int	middle_b;

	middle_a = info->size_a / 2;
	middle_b = info->size_b / 2;
	if ((b_elem->index > middle_b && b_elem->pair > middle_a)
		|| (b_elem->index <= middle_b && b_elem->pair <= middle_a))
		rr_or_rrr(s_a, s_b, b_elem, info);
	else
		norm_move(s_a, s_b, b_elem, info);
}

void	norm_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info)
{
	t_stack	*a_elem;
	int		middle_a;
	int		middle_b;

	middle_a = info->size_a / 2;
	middle_b = info->size_b / 2;
	a_elem = find_elem_by_index(s_a, b_elem->pair);
	if (b_elem->index > middle_b)
		while ((*s_b)->number != b_elem->number)
			ft_reverse_rotate(s_b, "rrb\n", info);
	else
		while ((*s_b)->number != b_elem->number)
			ft_rotate(s_b, "rb\n", info);
	if (b_elem->pair > middle_a)
		while ((*s_a)->number != a_elem->number)
			ft_reverse_rotate(s_a, "rra\n", info);
	else
		while ((*s_a)->number != a_elem->number)
			ft_rotate(s_a, "ra\n", info);
}

void	rr_or_rrr(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info)
{
	t_stack	*a_elem;
	int		middle_a;
	int		middle_b;

	middle_a = info->size_a / 2;
	middle_b = info->size_b / 2;
	a_elem = find_elem_by_index(s_a, b_elem->pair);
	if (b_elem->index <= middle_b)
	{
		while ((*s_a)->number != a_elem->number
			&& (*s_b)->number != b_elem->number)
			ft_rr(s_a, s_b, "rr\n", info);
		while ((*s_a)->number != a_elem->number)
			ft_rotate(s_a, "ra\n", info);
		while ((*s_b)->number != b_elem->number)
			ft_rotate(s_b, "rb\n", info);
	}
	else
		rrr_move(s_a, s_b, b_elem, info);
}

void	rrr_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info)
{
	t_stack	*a_elem;
	int		middle_a;
	int		middle_b;

	middle_a = info->size_a / 2;
	middle_b = info->size_b / 2;
	a_elem = find_elem_by_index(s_a, b_elem->pair);
	while ((*s_a)->number != a_elem->number && (*s_b)->number != b_elem->number)
		ft_rrr(s_a, s_b, "rrr\n", info);
	while ((*s_a)->number != a_elem->number)
		ft_reverse_rotate(s_a, "rra\n", info);
	while ((*s_b)->number != b_elem->number)
		ft_reverse_rotate(s_b, "rrb\n", info);
}
