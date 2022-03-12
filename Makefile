NAME = push_swap

CC_FLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

CC = cc

SRC = ft_sort_three.c moves2.c ft_split.c push_a_to_b.c calcul_best_elem.c ft_strlcpy.c push_b_to_a.c check_arguments.c ft_strlen.c check_error.c largest_increasing_sub.c push_swap_utils.c main.c \
	push_swap_utils2.c ft_sort_five.c moves1.c stack_utils.c
OBG = ft_sort_three.o moves2.o ft_split.o push_a_to_b.o calcul_best_elem.o ft_strlcpy.o push_b_to_a.o check_arguments.o ft_strlen.o check_error.o largest_increasing_sub.o push_swap_utils.o main.o \
	push_swap_utils2.o ft_sort_five.o moves1.o stack_utils.o
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CC_FLAGS) $(OBG) -o $(NAME)

%.o : %.c
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all