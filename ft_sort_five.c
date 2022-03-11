/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:16:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/11 20:34:12 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_under_five(t_stack **s_a, t_stack **s_b, t_info *info)
{
	if (stack_is_sorted(*s_a) == 0)
		return ;
	if (info->size_a > 5)
		return ;
	if (info->size_a == 2)
		ft_swap(s_a, "sa\n", info);
	else if (info->size_a == 3)
		ft_sort_three(s_a, info);
	else if (info->size_a == 4)
	{
		min_in_top(s_a, info);
		ft_push(s_a, s_b, "pb\n", info);
		ft_sort_three(s_a, info);
		ft_push(s_b, s_a, "pa\n", info);
	}
	else
	{
		min_in_top(s_a, info);
		ft_push(s_a, s_b, "pb\n", info);
		min_in_top(s_a, info);
		ft_push(s_a, s_b, "pb\n", info);
		ft_sort_three(s_a, info);
		ft_push(s_b, s_a, "pa\n", info);
		ft_push(s_b, s_a, "pa\n", info);
	}
}
