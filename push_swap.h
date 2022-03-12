/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:04:11 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 19:59:32 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<sys/types.h>
# include<sys/uio.h>
# include<fcntl.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX "2147483647"
# define MIN "2147483648"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


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

void	calculate_best_elem(t_stack *b_elem, t_info *info);
int		calcul_moves(t_stack *b_elem, t_info *info);
void	marking_best_elem(t_stack **stack_a, t_stack **stack_b, t_info *info);
t_stack	*min_move(t_stack **stack_b, t_info *info);
void	b_to_a(t_stack **stack_a, t_stack **stack_b, t_info *info);
void	check_the_only_arg(t_stack **stack_a, t_info *info, char *arg);
t_stack	*max_of_stack(t_stack *stack);
void	get_stack_v2(t_stack **stack_a, char **av, t_info *info, int ac);
int		check_duplicate(t_stack *stack, int value);
void	ft_error(void);
int		ft_strcmp(char *str1, char *str2);
int		is_integer(char *num);
void	ft_sort_under_five(t_stack **s_a, t_stack **s_b, t_info *info);
void	sort_five(t_stack **s_a, t_stack **s_b, t_info *info);
void	ft_sort_three(t_stack **stack, t_info *info);
void	sort_three_a(t_stack **stack, t_info *info);
void	sort_three_b(t_stack **stack, t_info *info);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
t_stack	*max_of_length(t_stack **stack);
t_stack	*find_elem_by_index(t_stack **stack, int index);
void	get_lis(t_stack **stack);
void	find_lis(t_stack **stack);
void	stack_init(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	check_arguments(int ac, char **av);
void	get_stack(t_stack **stack_a, char **av, t_info *info, int ac);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_info *info);
void	ft_swap(t_stack **stack, char *move, t_info *info);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char *move);
t_stack	*ft_last_elem(t_stack *stack);
void	ft_rotate(t_stack **stack, char *move);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, char *move);
void	ft_reverse_rotate(t_stack **stack, char *move, t_info *info);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, char *move, t_info *info);
void	ft_print_move(char *move);
int		ft_max(int a, int b);
void	a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info);
void	elem_pos(t_stack **stack_a, t_stack *elem);
void	mv_to_top(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
void	norm_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
void	rr_or_rrr(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
void	rrr_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem, t_info *info);
int		ft_atoi(char *number);
int		is_number(char *num);
int		check_number(char *num);
int		stack_is_sorted(t_stack *stack);
void	min_in_top(t_stack **stack, t_info *info);
t_stack	*min_elem(t_stack *stack);
int		ft_min(int value1, int value2);
void	index_stack(t_stack **stack);
t_stack	*initialiser(void);
int		is_empty(t_stack *s);
void	push(t_stack **s, int value);
int		pop(t_stack **s, int *value);
int		fill_stack(t_stack **s, char *arg);

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

/* BOUNUS FILES*/
int		three_len_move(char *move);
int		four_len_move(char *move);
int		check_valid_move(char *move);
void	perform_move(t_stack **s_a, t_stack **s_b, int move, t_info *info);
void	check_moves(t_stack **stack_a, t_stack **stack_b, t_info *info, int fd);


#endif