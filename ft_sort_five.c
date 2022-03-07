/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:16:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/07 21:16:44 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_min_to_B(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    int min;
    int size;

    size = (*stack_size)->size;
    if (size <= 3)
        return ;
    min = min_stack(*stack_a, (*stack_size)->size);
    if (min <= size / 2)
    {
        min--;
        while (min > 0)
        {
            ft_rotate_a(stack_a,stack_size);
            min--;
        }
        ft_pb(stack_a, stack_b, stack_size, stack_size2);
    }
    else
    {
        min--;
        while (min != size)
        {
            ft_reverse_rotate_a(stack_a, stack_size);
            min++;
        }
        ft_pb(stack_a, stack_b, stack_size, stack_size2);
    }
}

void    ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    push_min_to_B(stack_a, stack_b, stack_size, stack_size2);
    push_min_to_B(stack_a, stack_b, stack_size, stack_size2);
    ft_sort_three(stack_a, stack_size);
    ft_pa(stack_a, stack_b, stack_size, stack_size2);
    ft_pa(stack_a, stack_b, stack_size, stack_size2);
}