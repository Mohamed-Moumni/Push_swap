/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:31:21 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/14 19:35:47 by mmoumni          ###   ########.fr       */
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

int	check_space(char *string)
{
	int	i;

	i = 0;
	if (string[0] == '\0')
		return (1);
	while (string[i])
	{
		if (string[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

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
	if (ft_strcmp(move, "ss\n") == 0)
		return (10);
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
