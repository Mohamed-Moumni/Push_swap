/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:58:20 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/13 11:57:50 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_len_move(char *move)
{
	if (ft_strcmp(move, "ra\n") == 0)
		return (0);
	if (ft_strcmp(move, "rb\n") == 0)
		return (1);
	if (ft_strcmp(move, "sa\n") == 0)
		return (2);
	if (ft_strcmp(move, "sb\n") == 0)
		return (3);
	if (ft_strcmp(move, "rr\n") == 0)
		return (4);
	if (ft_strcmp(move, "pa\n") == 0)
		return (5);
	if (ft_strcmp(move, "pb\n") == 0)
		return (6);
	return (-1);
}

int	four_len_move(char *move)
{
	if (ft_strcmp(move, "rrr\n") == 0)
		return (7);
	if (ft_strcmp(move, "rra\n") == 0)
		return (8);
	if (ft_strcmp(move, "rrb\n") == 0)
		return (9);
	return (-1);
}

int	check_valid_move(char *move)
{
	int	length;

	length = ft_strlen(move);
	if (length == 3)
	{
		if (three_len_move(move) == -1)
			ft_error();
		else
			return (three_len_move(move));
	}
	else if (length == 4)
	{
		if (four_len_move(move) == -1)
			ft_error();
		else
			return (four_len_move(move));
	}
	return (-1);
}

void	perform_move(t_stack **s_a, t_stack **s_b, int move, t_info *info)
{
	if (move == 0)
		ft_rotate(s_a, "");
	else if (move == 1)
		ft_rotate(s_b, "");
	else if (move == 2)
		ft_swap(s_a, "", info);
	else if (move == 3)
		ft_swap(s_b, "", info);
	else if (move == 4)
		ft_rr(s_a, s_b, "");
	else if (move == 5)
		ft_push(s_b, s_a, "");
	else if (move == 6)
		ft_push(s_a, s_b, "");
	else if (move == 7)
		ft_rrr(s_a, s_b, "", info);
	else if (move == 8)
		ft_reverse_rotate(s_a, "", info);
	else
		ft_reverse_rotate(s_b, "", info);
}

void	check_moves(t_stack **stack_a, t_stack **stack_b, t_info *info, int fd)
{
	char	*move;
	int		move_type;
	int		check;

	check = 0;
	move = get_next_line(fd);
	while (move != NULL && move[0] != '\n')
	{
		check = 1;
		move_type = check_valid_move(move);
		if (move_type != -1)
			perform_move(stack_a, stack_b, move_type, info);
		else
		{
			free(move);
			ft_error();
		}
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

	if (ac == 2)
	{
		stack_init(&stack_a, &stack_b, &info);
		check_the_only_arg(&stack_a, info, av[1]);
		check_moves(&stack_a, &stack_a, info, 0);
		if (stack_is_sorted(stack_a))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else if (ac > 2)
	{
		stack_init(&stack_a, &stack_b, &info);
		check_arguments(ac, av);
		get_stack(&stack_a, av, info, ac);
		check_moves(&stack_a, &stack_b, info, 0);
		if (stack_is_sorted(stack_a))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	return (0);
}
