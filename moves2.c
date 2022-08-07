/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:03 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/22 13:13:24 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info)
{
	ft_rotate(stack_a, "", info);
	ft_rotate(stack_b, "", info);
	ft_print_move(move);
}

void	ft_reverse_rotate(t_stack **stack, char *move, t_info *info)
{
	int		poped_elem;
	t_stack	*before_last;
	t_stack	*old_head;
	t_stack	*new_head;

	(void) info;
	if ((*stack) == NULL || ft_count_elem(*stack) < 2)
		return ;
	before_last = (*stack);
	old_head = *stack;
	while ((before_last)->next->next != NULL)
		before_last = before_last->next;
	poped_elem = before_last->next->number;
	new_head = before_last->next;
	new_head->next = old_head;
	*stack = new_head;
	before_last->next = NULL;
	ft_print_move(move);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info)
{
	ft_reverse_rotate(stack_a, "", info);
	ft_reverse_rotate(stack_b, "", info);
	ft_print_move(move);
}

void	ft_print_move(char *move)
{
	int	i;

	i = 0;
	while (move[i])
	{
		write(1, &move[i], 1);
		i++;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
