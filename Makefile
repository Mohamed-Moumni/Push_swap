NAME = push_swap

CC_FLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

CC = cc

SRC = 

OBG =
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