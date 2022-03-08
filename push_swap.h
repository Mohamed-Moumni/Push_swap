/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:27 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/08 19:26:14 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX "2147483647"
#define MIN "2147483648"

typedef struct  s_size
{
    int size;
}   t_size;

typedef struct s_stack
{
    int             number;
    int             lis;
    int             length;
    int             prev;
    int             index;
    struct s_stack  *next;
}t_stack;

t_stack *initialiser();
int     is_empty(t_stack *s);
void    push(t_stack **s, int value, t_size **stack_size);
int     pop(t_stack **s, int *value, t_size **stack_size);
t_stack *ft_last_elem(t_stack *stack);
void    ft_swap_a(t_stack **stack);
void    ft_swap_b(t_stack **stack);
void    ft_ss(t_stack **stack_a, t_stack **stack_b);
void    ft_pa(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    ft_pb(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
t_stack *ft_last_elem(t_stack *stack);
void    ft_rotate_a(t_stack **stack, t_size **stack_size);
void    ft_rotate_b(t_stack **stack, t_size **stack_size);
void    ft_reverse_rotate_a(t_stack **stack, t_size **stack_size);
void    ft_reverse_rotate_b(t_stack **stack, t_size **stack_size);
void    ft_rr(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    ft_rrr(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    print_stack(t_stack *stack);
int     ft_atoi(char *number);
int     fill_stack(t_stack **s, char *arg, t_size **stack_size);
int     check_duplicate(t_stack *stack, int value);
void	ft_error(void);
int     ft_strcmp(char *str1, char *str2);
int     check_number(char *num);
int     is_integer(char *num);
void    ft_sort_three(t_stack **stack, t_size **stack_size);
int     min_stack(t_stack *stack, int size);
void    ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    push_min_to_B(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    print_stack(t_stack *stack);
int     stack_is_sorted(t_stack *stack);
void	get_lis(t_stack **stack, t_size **stack_size);
t_stack *find_elem_by_index(t_stack **stack, int prev);
t_stack *max_of_length(t_stack **stack);
void	lis_in_stack(t_stack **stack, int size);
void    A_to_B(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    index_stack(t_stack **stack);
void    elem_pos(t_stack **s_a, t_stack *elem, t_size *size);
void    sort_all(t_stack **s_a ,t_stack **s_b, t_size *size, t_size *size2);
void    B_to_A(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
t_stack *min_elem(t_stack *stack, int size);
int     max(int a, int b);
void    calculate_best_elem(t_stack *b_elem, t_size *size, t_size *size2);
void    sort_all(t_stack **s_a ,t_stack **s_b, t_size *size, t_size *size2);
t_stack *min_move(t_stack **stack_b);
void    B_to_A(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2);
void    double_or_riple_r(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem);
void    normal_moves(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem);
void    move_to_top(t_stack **stack_a, t_stack **stack_b, t_size **stack_size, t_size **stack_size2, t_stack *b_elem);
int max_stack(t_stack *stack, int size);
void    print_stack(t_stack *stack);
void    find_lis(t_stack **stack);
int max(int a, int b);

#endif