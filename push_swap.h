#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



#define MAX_INT 2147483647
#define MIN_INT 
#define MAX "2147483647"
#define MIN "2147483648"


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
int     ft_atoi(char *number);
int fill_stack(t_stack **s, char *arg);
int check_duplicate(t_stack *stack, int value);
void	ft_error(void);
int ft_strcmp(char *str1, char *str2);
int    check_number(char *num);
int is_integer(char *num);

#endif