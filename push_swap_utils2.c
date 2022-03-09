/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:23 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/09 19:13:05 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int min_stack(t_stack *stack, int size)
// {
//     t_stack *tmp_stack;
//     int      min;
//     int     count;
//     int     min_pos;

//     count = 0;
//     min_pos = 1;
//     min = stack->number;
//     tmp_stack = stack->next;;
//     while (min_pos < size)
//     {
//         min_pos++;
//         if (tmp_stack->number <= min)
//         {
//             min = tmp_stack->number;
//             count = min_pos;
//         }
//         tmp_stack = tmp_stack->next;
//     }
//     return (count);
// }

// t_stack	*min_elem(t_stack *stack, int size)
// {
// 	t_stack	*tmp_stack;
// 	t_stack	*minimum;
// 	int		i;

// 	tmp_stack = stack;
// 	minimum = stack;
// 	while (tmp_stack)
// 	{
// 		if (tmp_stack->number <= minimum->number)
// 			minimum = tmp_stack;
// 		tmp_stack = tmp_stack->next;
//     }
// 	return (minimum);
// }

int max_stack(t_stack *stack, int size)
{
    t_stack *tmp_stack;
    int     max;

    max = 0;
    tmp_stack = stack;
    while (tmp_stack)
    {
        if (max < tmp_stack->number)
        {
            max = tmp_stack->index;
        }
        tmp_stack = tmp_stack->next;
    }
    return (max);
}


