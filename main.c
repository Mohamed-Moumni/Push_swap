/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:27:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 18:15:22 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (tmp_stack)
	{
		printf("%d\n", tmp_stack->number);
		tmp_stack = tmp_stack->next;
	}
}

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

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	ft_sort_under_five(stack_a, stack_b, info);
	if (info->size_a <= 5)
		exit(0);
	find_lis(stack_a);
	get_lis(stack_a);
	a_to_b(stack_a, stack_b, info);
	index_stack(stack_a);
	index_stack(stack_b);
	b_to_a(stack_a, stack_b, info);
	index_stack(stack_a);
	min_in_top(stack_a, info);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	if (ac == 2)
	{
		stack_init(&stack_a, &stack_b, &info);
		check_the_only_arg(&stack_a, info, av[1]);
		sort_stack(&stack_a, &stack_b, info);
	}
	else if (ac > 2)
	{
		stack_init(&stack_a, &stack_b, &info);
		check_arguments(ac, av);
		get_stack(&stack_a, av, info, ac);
		sort_stack(&stack_a, &stack_b, info);
	}
	else
		return (0);
}
