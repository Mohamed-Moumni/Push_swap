/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:27 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/10 21:40:55 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX "2147483647"
# define MIN "2147483648"

typedef struct s_info
{
	int	size_a;
	int	size_b;
}t_info;

typedef struct s_stack
{
	int				number;
	int				lis;
	int				lis_len;
	int				prev;
	int				dis;
	int				pair;
	int				index;
	struct s_stack	*next;
}t_stack;

t_stack	*initialiser(void);
int		is_empty(t_stack *s);
void	push(t_stack **s, int value, t_info *info);
int		pop(t_stack **s, int *value, t_info *info);
int		fill_stack(t_stack **s, char *arg, t_info *info);
void	ft_print_move(char *move);
void	ft_swap(t_stack **stack, char *move, t_info *info);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info);
t_stack	*ft_last_elem(t_stack *stack);
void	ft_rotate(t_stack **stack, char *move, t_info *info);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info);
void	ft_reverse_rotate(t_stack **stack, char *move, t_info *info);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info);
int		check_duplicate(t_stack *stack, int value);
void	ft_error(void);
int		ft_strcmp(char *str1, char *str2);
int		is_integer(char *num);
t_stack	*max_of_length(t_stack **stack);
t_stack	*find_elem_by_index(t_stack **stack, int index);
void	get_lis(t_stack **stack);
void	find_lis(t_stack **stack);
int		stack_is_sorted(t_stack *stack);
int		check_number(char *num);
int		is_number(char *num);
int		ft_atoi(char *number);
int		ft_max(int a, int b);
void	print_stack(t_stack *stack);
void	a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info);
t_stack	*min_elem(t_stack *stack, int size, t_info *info);
int		ft_min(int value1, int value2);
void	index_stack(t_stack **stack, t_info *info);
void	elem_pos(t_stack **stack_a, t_stack *elem, t_info *info);
void	mv_to_top(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
void	norm_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
void	rr_or_rrr(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
void	calculate_best_elem(t_stack *b_elem, t_info *info);
void	marking_best_elem(t_stack **stack_a, t_stack **stack_b, t_info *info);
t_stack	*min_move(t_stack **stack_b, t_info *info);
void	b_to_a(t_stack **stack_a, t_stack **stack_b, t_info *info);
void	min_in_top(t_stack **stack, t_info *info);
int		calcul_moves(t_stack *b_elem, t_info *info);
void	rrr_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);

#endif