/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:04:26 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/15 21:20:50 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_duplicate(t_stack *stack, int value)
{
	t_stack	*tmp_stack;
	int		i;

	i = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		if (value == tmp_stack->number)
		{
			i++;
			if (i == 2)
				return (1);
		}
		tmp_stack = tmp_stack->next;
	}
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

int	is_integer(char *num)
{
	int	i;
	int	plus;

	i = 0;
	plus = 0;
	while (num[i])
		i++;
	if (num[0] == '-' || num[0] == '+')
	{
		plus = 1;
		i -= 1;
	}
	if (i > 10)
		return (1);
	if (i == 10)
	{
		if (ft_strcmp(&num[plus], MIN) > 0)
			return (1);
		else
			if (ft_strcmp(&num[plus], MAX) < 0)
				return (1);
	}
	return (0);
}
