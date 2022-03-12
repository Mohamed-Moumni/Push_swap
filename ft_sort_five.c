/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:16:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 18:14:11 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_under_five(t_stack **s_a, t_stack **s_b, t_info *info)
{
	if (stack_is_sorted(*s_a) == 0)
		exit(0);
	if (info->size_a > 5)
		return ;
	if (info->size_a == 2)
		ft_swap(s_a, "sa\n", info);
	else if (info->size_a == 3)
		ft_sort_three(s_a, info);
	else if (info->size_a == 4)
	{
		min_in_top(s_a, info);
		ft_push(s_a, s_b, "pb\n");
		ft_sort_three(s_a, info);
		ft_push(s_b, s_a, "pa\n");
	}
	sort_five(s_a, s_b, info);
}

void	sort_five(t_stack **s_a, t_stack **s_b, t_info *info)
{
	min_in_top(s_a, info);
	ft_push(s_a, s_b, "pb\n");
	info->size_a -= 1;
	info->size_b += 1;
	index_stack(s_a);
	index_stack(s_b);
	min_in_top(s_a, info);
	ft_push(s_a, s_b, "pb\n");
	info->size_a -= 1;
	info->size_b += 1;
	index_stack(s_a);
	ft_sort_three(s_a, info);
	ft_push(s_b, s_a, "pa\n");
	info->size_a += 1;
	info->size_b -= 1;
	ft_push(s_b, s_a, "pa\n");
	info->size_a += 1;
	info->size_b -= 1;
}
