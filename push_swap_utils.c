#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *number)
{
	int			i;
	int			sign;
	int			result;
	
	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(number[i]))
		i++;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			sign = -1;
		i++;
	}
	while (number[i] && (number[i] >= '0' && number[i] <= '9'))
	{
		result = result * 10 + number[i] - '0';
		i++;
	}
	return ((sign * result));
}

int	is_number(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == '-' || num[i] == '+')
			i++;
		if (num[i] < '0' || num[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_number(char *num)
{
	if (is_number(num))
		ft_error();
	if (is_integer(num))
		ft_error();
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack *tmp_stack;
	int		length;

	length = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		if (tmp_stack->next && tmp_stack->number  > tmp_stack->next->number)
		return (1);
		length++;
		tmp_stack = tmp_stack->next;
	}
	if (length == 0 || length == 1)
		return (1);
	return (0);
}