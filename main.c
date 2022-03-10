/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:27:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/10 21:01:05 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		j;
	int		value;
	t_info	*info;

	j = ac - 2;
	i = ac - 1;
	if (ac > 2)
	{
		stack_a = initialiser();
		stack_b = initialiser();
		info = NULL;
		info = malloc(sizeof(t_info));
		info->size_a = 0;
		info->size_b = 0;
		while (i > 0)
		{
			if (check_number(av[i]) == 0)
			{
				value = fill_stack(&stack_a, av[i], info);
				if (i < ac - 2)
				{
					if (check_duplicate(stack_a, value))
						ft_error();
				}
				stack_a->lis_len = 1;
				stack_a->prev = -1;
				stack_a->index = j;
			}
			info->size_a += 1;
			j--;
			i--;
		}
		find_lis(&stack_a);
		get_lis(&stack_a);
		a_to_b(&stack_a, &stack_b, info);
		index_stack(&stack_a, info);
		index_stack(&stack_b, info);
		B_to_A(&stack_a, &stack_b, info);
		index_stack(&stack_a, info);
		min_in_top(&stack_a, info);
	}
	return (0);
}
