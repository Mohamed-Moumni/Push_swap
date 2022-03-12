/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:20:01 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 18:15:07 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_the_only_arg(t_stack **stack_a, t_info *info, char *arg)
{
	int		i;
	char	**args;

	args = ft_split(arg, ' ');
	i = 0;
	while (args[i] != NULL)
	{
		if (check_number(args[i]) == 1)
			ft_error();
		i++;
	}
	i++;
	get_stack_v2(stack_a, args, info, i);
}

t_stack	*max_of_stack(t_stack *stack)
{
	t_stack	*tmp_stack;
	t_stack	*max_stack;
	int		max;

	max = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		if (tmp_stack->number > max)
		{
			max = tmp_stack->number;
			max_stack = tmp_stack;
		}
		tmp_stack = tmp_stack->next;
	}
	return (max_stack);
}

void	get_stack_v2(t_stack **stack_a, char **av, t_info *info, int ac)
{
	int	i;
	int	value;
	int	j;

	i = ac - 2;
	j = ac - 2;
	while (i >= 0)
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
