/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_B_to_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:15 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/09 19:22:41 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        tmp_stack->dis = 0;
        tmp_stack->pair = 0;
		i++;
		tmp_stack = tmp_stack->next;
	}
}

void	elem_pos(t_stack **stack_a, t_stack *elem, t_info *info)
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
		tmp_stack = min_elem(*stack_a, info->size_a);
		elem->pair = tmp_stack->index;
	}
}

void    move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *b_elem, t_info *info)
{
    int middle_a;
    int middle_b;

    middle_a = 0;
    middle_b = 0;
    middle_a = info->size_a / 2 + 1;
    middle_b = info->size_b / 2 + 1;
    if ((b_elem->index > middle_b && b_elem->pair > middle_a) || (b_elem->index <= middle_b && b_elem->pair <= middle_a))
        double_or_riple_r(stack_a, stack_b, b_elem, info);
    else
        normal_moves(stack_a, stack_b, b_elem, info);
}

void    normal_moves(t_stack **stack_a, t_stack **stack_b, t_stack *b_elem, t_info *info)
{
    int		middle_a;
    int		middle_b;
    t_stack	*a_elem;

    middle_a = 0;
    middle_b = 0;
    middle_a = info->size_a / 2 + 1;
    middle_b = info->size_a / 2 + 1;
    a_elem = find_elem_by_index(stack_a, b_elem->pair);
    if (b_elem->index > middle_b)
    {
        while ((*stack_b)->number != b_elem->number)
            ft_reverse_rotate(stack_b, "rrb\n", info);
    }
    else
    {
        while ((*stack_b)->number != b_elem->number)
            ft_rotate(stack_b, "rb\n", info);
    }
    if (b_elem->pair > middle_a)
    {
        while ((*stack_a)->number != a_elem->number)
            ft_reverse_rotate(stack_a, "rra\n", info);
    }
    else
    {
        while ((*stack_a)->number != a_elem->number)
            ft_rotate(stack_a, "ra\n", info);
    }
}

void    double_or_riple_r(t_stack **stack_a, t_stack **stack_b, t_stack *b_elem, t_info *info)
{
    int		middle_a;
    int		middle_b;
    int		moves;
    t_stack	*a_elem;

    middle_a = 0;
    middle_b = 0;
    middle_a = info->size_a / 2 + 1;
    middle_b = info->size_b / 2 + 1;
    a_elem = find_elem_by_index(stack_a, b_elem->pair);
    if (b_elem->index <= middle_b)
    {
        while ((*stack_a)->number != a_elem->number && (*stack_b)->number != b_elem->number)
            ft_rr(stack_a, stack_b, "rr\n", info);
        while ((*stack_a)->number != a_elem->number)
            ft_rotate(stack_a, "ra\n", info);
        while ((*stack_b)->number != b_elem->number)
            ft_rotate(stack_b, "rb\n", info);
    }
    else
    {
        while ((*stack_a)->number != a_elem->number && (*stack_b)->number != b_elem->number)
        {
            ft_rrr(stack_a, stack_b, "rrr\n", info);
        }
        while ((*stack_a)->number != a_elem->number)
            ft_reverse_rotate(stack_a, "rra\n", info);
        while ((*stack_b)->number != b_elem->number)
			ft_reverse_rotate(stack_b, "rrb\n", info);
    }
}