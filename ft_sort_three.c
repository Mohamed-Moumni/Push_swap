/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:16:49 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/10 21:54:40 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_sort_three(t_stack **stack, t_info *info)
{
    t_stack *tmp_curr;
    t_stack *tmp_next;

    if (stack_is_sorted(*stack) == 0)
        return ;
    tmp_curr = *stack;
    tmp_next = (*stack)->next;
    if (tmp_curr->number < tmp_next->number)
    {
        if (tmp_next->next->number > tmp_curr->number)
            {
                ft_reverse_rotate(stack, "rra\n", info);
                ft_swap(stack, "sa\n", info);
            }
        else
            ft_reverse_rotate(stack, "rra\n", info);
    }
    else if (tmp_next->number < tmp_curr->number && tmp_next->number < tmp_next->next->number)
    {
        if (tmp_curr->number < tmp_next->next->number)
            ft_swap(stack, "sa\n", info);
        else
            ft_rotate(stack, "ra\n", info);
    }
    else
    {
        ft_swap(stack, "sa\n", info);
        ft_reverse_rotate(stack, "rra\n", info);
    }
}

void	sort_three_one(t_stack **stack, t_info *info)
{
	
}

t_stack **sta