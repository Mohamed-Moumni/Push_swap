/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:27:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/07 21:40:33 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_in_top(t_stack **stack, t_size **stack_size)
{
	t_stack	*tmp_stack;
	int		min;
	int		middle;
	
    tmp_stack = min_elem(*stack, (*stack_size)->size);
    min = tmp_stack->index;
    middle = (*stack_size)->size / 2;
    if (min > middle)
    {
        min = (*stack_size)->size - (tmp_stack->index + 1) + 1;
    while (min--)
    {
        ft_reverse_rotate_a(stack, stack_size);
    }
    }
    else
    {
        while (min--)
        {
            ft_rotate_a(stack, stack_size);
        }
    }
}

int main(int ac, char **av)
{
    t_stack *stack;
    t_stack *stack2;
    t_stack *tmp_stack;
    t_stack *tmp_stack2;
    t_size  *stack_size;
    t_size  *stack_size2;
    int i;
    int j;
    int value;

    j = ac - 2;
    i = ac - 1;
    if (ac > 2)
    {
        stack = initialiser();
        stack2 = initialiser();
        stack_size = malloc(sizeof(t_size));
        stack_size2 = malloc(sizeof(t_size));

        stack_size->size = 0;
        stack_size2->size = 0;
        while(i > 0)
        {
            if (check_number(av[i]) == 0)
            {
                value = fill_stack(&stack, av[i], &stack_size);
                if (i < ac - 2)
                {
                    if(check_duplicate(stack, value))
                        ft_error();
                }
                stack->length = 1;
                stack->prev = -1;
                stack->index = j;
            }
            j--;
            i--;
        }
        index_stack(&stack);
        lis_in_stack(&stack, stack_size->size);
        get_lis(&stack, &stack_size);
        A_to_B(&stack, &stack2, &stack_size, &stack_size2);
        B_to_A(&stack, &stack2, &stack_size, &stack_size2);
        index_stack(&stack);
        min_in_top(&stack, &stack_size);
        // print_stack(stack);
    }
    return (0);
}