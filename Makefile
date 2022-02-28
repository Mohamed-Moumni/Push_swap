NAME = push_swap

CC_FLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

CC = cc

SRC = check_error.c ft_sort_all.c ft_sort_five.c largest_increasing_sub.c moves_a.c moves_b.c push_swap_utils.c push_swap_utils2.c stack_test.c

OBG = check_error.o ft_sort_all.o ft_sort_five.o largest_increasing_sub.o moves_a.o moves_b.o push_swap_utils.o push_swap_utils2.o stack_test.o
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CC_FLAGS) $(OBG) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all