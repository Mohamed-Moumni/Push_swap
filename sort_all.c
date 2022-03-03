#include "push_swap.h"

int same_sign(int a, int b)
{
    if (a >= 0 && b >= 0)
        return (1);
    else if (a < 0 && b < 0)
        return (1);
    return(0);
}

int min_num(int a, int b)
{
    if (a < b)
        return(a);
    return (b);
}

int ft_abs(int a)
{
    if (a < 0)
        return (-a);
    return(a);
}

void    sort_all(t_stack **s_a ,t_stack **s_b, t_size *size, t_size *size2)
{
    t_stack *tmp_stack;
    int     move;

    tmp_stack = *s_b;
    while (tmp_stack)
    {
        move = elem_pos(s_a, tmp_stack, size);
        best_move(tmp_stack, move, size, size2);
        tmp_stack = tmp_stack->next;
    }
}

void    sort(t_stack **stack_a, t_stack **stack_b, t_stack *tmp_stack,t_size **stack_size, t_size **stack_size2)
{
    int move;
    int min;
    int diff;

    if (same_sign(tmp_stack->prev, tmp_stack->lis))
    {
        if (tmp_stack->prev < 0)
        {
            min = ((*stack_size2)->size / 2) - min_num(ft_abs(tmp_stack->prev), ft_abs(tmp_stack->lis)) + 1;
            while (min--)
                ft_rrr(stack_a, stack_b, stack_size, stack_size2);
            diff = ft_abs(tmp_stack->prev) - ft_abs(tmp_stack->lis) - 1;
            if (diff > 0)
            {
                while (diff--)
                {
                    ft_reverse_rotate_b(stack_b,stack_size2);
                }
            }
            else
            {
                while (++diff)
                {
                    ft_reverse_rotate_a(stack_a,stack_size);
                }
            }
    }
    else
    {
            min = min_num(ft_abs(tmp_stack->prev), ft_abs(tmp_stack->lis));
            while (min--)
                ft_rr(stack_a, stack_b, stack_size, stack_size2);
            diff = ft_abs(tmp_stack->prev) - ft_abs(tmp_stack->lis) - 1;
            if (diff > 0)
            {
                while (diff--)
                {
                    ft_rotate_b(stack_b,stack_size2);
                }
            }
            else
            {
                while (++diff)
                {
                    ft_rotate_a(stack_a,stack_size);
                }
            }   
    }
    }
    else
    {
        if (tmp_stack->prev < tmp_stack->lis)
        {
            move = ((*stack_size2)->size / 2) - abs(tmp_stack->prev) + 1;
            while (move--)
                ft_reverse_rotate_b(stack_b, stack_size2);
            move = tmp_stack->lis;
            while (move--)
                ft_rotate_a(stack_a, stack_size);
        }
        else
        {
            move = ((*stack_size)->size / 2) - abs(tmp_stack->lis) + 1;
            while (move--)
                ft_reverse_rotate_a(stack_a, stack_size);
            move = tmp_stack->prev;
            while (move--)
                ft_rotate_b(stack_b, stack_size2);
        }
    }
}

int calulate_moves(int a, int b, int size1, int size2)
{
    int moves;

    moves = 0;
    if (a < 0)
        moves += size2 / 2 - abs(a) + 2;
    if (b < 0)
        moves += size1 / 2 - abs(b) + 2;
    if (a > 0)
        moves += a - 1;
    if (b > 0)
        moves += b - 1;
    return (moves);
}

void    best_move(t_stack *b_elem, int move, t_size *size, t_size *size2) 
{
    if (move == 1)
        (b_elem)->length = 1;
    else if(move == 2)
        (b_elem)->length = calulate_moves(b_elem->prev, b_elem->lis, size->size, size2->size);
    else if (move == 3)
        (b_elem)->length = calulate_moves(b_elem->prev, b_elem->lis, size->size, size2->size);
    else
        (b_elem)->length = 0;       
}

t_stack *min_move(t_stack **stack_b)
{
    t_stack *tmp_stack;
    int     min;
    t_stack *min_stack;

    tmp_stack = *stack_b;
    min = tmp_stack->length; 
    while (tmp_stack)
    {
        if (min >= tmp_stack->length)
        {
            min_stack = tmp_stack;
            min = tmp_stack->length;
            if (min == 1)
                return (min_stack);
        }
        tmp_stack = tmp_stack->next;
    }
    return (min_stack);
}
void    B_to_A(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2)
{
    t_stack *tmp_stack;
    int     size;

    size = (*stack_size2)->size;
    // printf("%d\n", size);
    // while (size--)
    // {
    //     index_stack(stack_b, *stack_size2);
    //     index_stack(stack_a, *stack_size);
    //     sort_all(stack_a, stack_b, *stack_size , *stack_size2);
    //     tmp_stack = min_move(stack_b);
    //     printf("%d--\n",tmp_stack->number);
    //     sort(stack_a, stack_b, tmp_stack, stack_size, stack_size2);
    //     // printf("here\n");
    //     ft_pa(stack_a, stack_b, stack_size, stack_size2);
    // }
    index_stack(stack_b, *stack_size2);
    index_stack(stack_a, *stack_size);
    sort_all(stack_a, stack_b, *stack_size , *stack_size2);
}