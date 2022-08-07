/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:58:20 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/21 17:18:46 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_move(t_stack **s_a, t_stack **s_b, int move, t_info *info)
{
	if (move == 0)
		ft_rotate(s_a, "", info);
	else if (move == 1)
		ft_rotate(s_b, "", info);
	else if (move == 2)
		ft_swap(s_a, "", info);
	else if (move == 3)
		ft_swap(s_b, "", info);
	else if (move == 4)
		ft_rr(s_a, s_b, "", info);
	else if (move == 5)
	{
		ft_push(s_b, s_a, "");
		info->size_b -= 1;
		info->size_a += 1;
	}
	else
		perform_move_two(s_a, s_b, move, info);
}

void	perform_move_two(t_stack **s_a, t_stack **s_b, int move, t_info *info)
{
	if (move == 6)
	{
		ft_push(s_a, s_b, "");
		info->size_a -= 1;
		info->size_b += 1;
	}
	else if (move == 7)
		ft_rrr(s_a, s_b, "", info);
	else if (move == 8)
		ft_reverse_rotate(s_a, "", info);
	else if (move == 9)
		ft_reverse_rotate(s_b, "", info);
	else
		ft_ss(s_a, s_b, "", info);
}

void	check_moves(t_stack **stack_a, t_stack **stack_b, t_info *info, int fd)
{
	char	*move;
	int		move_type;
	int		check;

	check = 0;
	move = get_next_line(fd);
	while (move != NULL)
	{
		check = 1;
		move_type = check_valid_move(move);
		if (move_type == -1)
		{
			free(move);
			ft_error();
		}
		else
			perform_move(stack_a, stack_b, move_type, info);
		free(move);
		move = get_next_line(0);
	}
	free(move);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;
	char	*full_arg;
	char	**argv;

	if (ac > 1)
	{
		stack_init(&stack_a, &stack_b, &info);
		full_arg = check_arguments(ac, av);
		argv = ft_split(full_arg, ' ');
		check_valid_numbers(ac, argv);
		get_stack(&stack_a, argv, info, ac);
		check_moves(&stack_a, &stack_b, info, 0);
		if (stack_b || stack_is_sorted(stack_a))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	return (0);
}
