NAME = ft_tail

CC = cc
CFLAG = -Wall -Wextra -Werror
SRC = ft_tail.c no_args.c
HEAD = ./includes/
OBJ= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAG) -c $< -I $(HEAD) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
