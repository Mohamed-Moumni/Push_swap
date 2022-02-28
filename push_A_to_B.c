#include "push_swap.h"

void    A_to_B(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    t_stack *tmp_stack;
    int     size;

    size = (*stack_size)->size;
    tmp_stack = *stack_a;
    while (size--)
    {
        if ((*stack_a)->lis == 1)
            ft_rotate_a(stack_a, stack_size);
        else
            ft_pb(stack_a,stack_b,stack_size, stack_size2);
    }
}
