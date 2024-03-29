/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:08 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/15 22:04:59 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	size;

	size = info->size_a - (max_of_length(stack_a)->lis_len);
	while (size != 0)
	{
		if ((*stack_a)->lis == 1)
		{
			ft_rotate(stack_a, "ra\n", info);
		}
		else
		{
			ft_push(stack_a, stack_b, "pb\n");
			size--;
			info->size_a -= 1;
			info->size_b += 1;
		}
	}
}

int	ft_count_elem(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		count;

	count = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		count++;
		tmp_stack = tmp_stack->next;
	}
	return (count);
}
