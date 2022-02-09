#include"push_swap.h"

void    ft_swap_ab(t_stack **stack)
{
    int tmp;
    int tmp_next;

    tmp = (*stack)->number;
    tmp_next = (*stack)->next->number;
    (*stack)->next->number = tmp;
    (*stack)->number = tmp_next;
}

void    ft_ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap_ab(stack_a);
    ft_swap_ab(stack_b);
}

void ft_pab(t_stack **stack_a, t_stack **stack_b)
{
    int poped_elem;

    poped_elem = 0;
    pop(stack_a, &poped_elem);
    push(stack_b, poped_elem);
}

t_stack *ft_last_elem(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return (tmp);
}

void ft_rotate_ab(t_stack **stack)
{
    int poped_elem;
    t_stack *bottom_stack;
    t_stack *node;

    poped_elem = 0;
    pop(stack, &poped_elem);
    bottom_stack = ft_last_elem(*stack);
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->number = poped_elem;
    node->next = NULL;
    bottom_stack->next = node;
}

void    ft_rr(t_stack **stack_a, t_stack **stack_b)
{
    ft_rotate_ab(stack_a);
    ft_rotate_ab(stack_b);
}

void    ft_reverse_rotate_ab(t_stack **stack)
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
    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return ;
    push(stack, poped_elem);
}

void    ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    ft_reverse_rotate_ab(stack_a);
    ft_reverse_rotate_ab(stack_b);
}
void    print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d\n",stack->number);
        stack = stack->next;
    }
}
// int main(void)
// {
//     t_stack *stack_a;
//     t_stack *stack_b;
//     t_stack *tmp;

//     stack_a = initialiser();
//     stack_b = initialiser();
//     push(&stack_a, 15);
//     push(&stack_a, 16);
//     push(&stack_a, 17);
//     push(&stack_a, 18);
//     push(&stack_a, 19);
//     push(&stack_a, 20);
//     push(&stack_b, 15);
//     push(&stack_b, 16);
//     push(&stack_b, 17);
//     push(&stack_b, 18);
//     push(&stack_b, 19);
//     push(&stack_b, 20);
//     // print_stack(stack);
//     // ft_pa(&stack_a, &stack_b);
//     // ft_pa(&stack_a, &stack_b);
//     // ft_pa(&stack_a, &stack_b);
//     // ft_pa(&stack_a, &stack_b);
//     // ft_pa(&stack_a, &stack_b);
//     // ft_pa(&stack_a, &stack_b);
//     // rotate_ab(&stack_a);
//     // rotate_ab(&stack_a);
//     // rotate_ab(&stack_a);
//     ft_rrr(&stack_a, &stack_b);
//     print_stack(stack_a);
//     printf("--------------------\n");
//     print_stack(stack_b);
//     return (0);
// }