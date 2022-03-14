/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/14 19:35:58 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack **stack, char *move, t_info *info)
{
	int	tmp;
	int	tmp_next;

	if ((*stack)->prev == -2)
	{
		if (info->size_a < 2)
			return ;
	}
	else if ((*stack)->prev == -3)
		if (info->size_b < 2)
			return ;
	tmp = (*stack)->number;
	tmp_next = (*stack)->next->number;
	(*stack)->next->number = tmp;
	(*stack)->number = tmp_next;
	ft_print_move(move);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info)
{
	index_stack(stack_a, -2);
	index_stack(stack_b, -3);
	ft_swap(stack_a, "", info);
	ft_swap(stack_b, "", info);
	ft_print_move(move);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, char *move)
{
	int	poped_elem;

	if ((*stack_a) == NULL)
		return ;
	poped_elem = 0;
	pop(stack_a, &poped_elem);
	push(stack_b, poped_elem);
	ft_print_move(move);
}

t_stack	*ft_last_elem(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_rotate(t_stack **stack, char *move, t_info *info)
{
	int		poped_elem;
	t_stack	*bottom_stack;
	t_stack	*node;

	if ((*stack)->prev == -2)
	{
		if (info->size_a < 2)
			return ;
	}
	else if ((*stack)->prev == -3)
		if (info->size_b < 2)
			return ;
	poped_elem = 0;
	pop(stack, &poped_elem);
	bottom_stack = ft_last_elem(*stack);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->number = poped_elem;
	node->next = NULL;
	bottom_stack->next = node;
	ft_print_move(move);
}
