#include<stdio.h>
#include<stdlib.h>

typedef struct s_stack
{
    int number;
    struct s_stack *next;
}t_stack;

t_stack *initialiser();
int is_empty(t_stack *s);
void push(t_stack **s, int value);
int pop(t_stack **s, int *value);
t_stack *ft_last_elem(t_stack *stack);
void ft_rotate_ab(t_stack **stack);
void    ft_ss(t_stack **stack_a, t_stack **stack_b);
void    ft_swap_ab(t_stack **stack);
void ft_pab(t_stack **stack_a, t_stack **stack_b);
void    ft_rr(t_stack **stack_a, t_stack **stack_b);
void    ft_reverse_rotate_ab(t_stack **stack);

