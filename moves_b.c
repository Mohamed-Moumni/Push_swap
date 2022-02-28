#include"push_swap.h"

void    ft_swap_b(t_stack **stack)
{
    int tmp;
    int tmp_next;

    tmp = (*stack)->number;
    tmp_next = (*stack)->next->number;
    (*stack)->next->number = tmp;
    (*stack)->number = tmp_next;
    write(1, "sb\n", 3);
}

void ft_pb(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    int poped_elem;

    if (*stack_a == NULL)
        return ;
    poped_elem = 0;
    pop(stack_a, &poped_elem, stack_size);
    push(stack_b, poped_elem, stack_size2);
    write(1, "pb\n", 3);
}

void ft_rotate_b(t_stack **stack, t_size **stack_size)
{
    int poped_elem;
    t_stack *bottom_stack;
    t_stack *node;

    poped_elem = 0;
    pop(stack, &poped_elem, stack_size);
    bottom_stack = ft_last_elem(*stack);
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->number = poped_elem;
    node->next = NULL;
    bottom_stack->next = node;
    (*stack_size)->size += 1;
    write(1, "rb\n", 3);
}

void    ft_reverse_rotate_b(t_stack **stack, t_size **stack_size)
{
    int poped_elem;
    t_stack *before_last;
    t_stack *node;

    before_last = (*stack);
    while ((before_last)->next->next != NULL)
    {
        before_last = before_last->next;
    }
    poped_elem = before_last->next->number;
    free(before_last->next);
    before_last->next = NULL;
    (*stack_size)->size -= 1;
    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return ;
    push(stack, poped_elem, stack_size);
    write(1, "rrb\n", 4);
}