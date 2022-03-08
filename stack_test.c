/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:37 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/08 12:15:41 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialiser(void)
{
	return (NULL);
}

int	is_empty(t_stack *s)
{
	if (s == NULL)
		return (1);
	else
		return (0);
}

void	push(t_stack **s, int value, t_size **stack_size)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->number = value;
	new_node->lis = 0;
	new_node->next = *s;
	*s = new_node;
	(*stack_size)->size += 1;
}

int	pop(t_stack **s, int *value, t_size **stack_size)
{
	t_stack	*tmp;

	if (is_empty(*s))
		return (1);
	*value = (*s)->number;
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	(*stack_size)->size -= 1;
	return (0);
}

int	fill_stack(t_stack **s, char *arg, t_size **stack_size)
{
	int	value;

	value = ft_atoi(arg);
	push(s, value, stack_size);
	return (value);
}
