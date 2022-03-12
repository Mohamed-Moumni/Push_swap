/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:31:21 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 20:32:00 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	*stack_a = initialiser();
	*stack_b = initialiser();
	*info = malloc(sizeof(t_info));
	(*info)->size_a = 0;
	(*info)->size_b = 0;
}

void	check_arguments(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if (check_number(av[i]) == 1)
			ft_error();
		i--;
	}
}

void	get_stack(t_stack **stack_a, char **av, t_info *info, int ac)
{
	int	i;
	int	value;
	int	j;

	i = ac - 1;
	j = ac - 2;
	while (i > 0)
	{
		value = fill_stack(stack_a, av[i]);
		if (i < ac - 2)
		{
			if (check_duplicate(*stack_a, value))
				ft_error();
		}
		(*stack_a)->lis_len = 1;
		(*stack_a)->prev = -1;
		(*stack_a)->index = j;
		info->size_a += 1;
		j--;
		i--;
	}
}
