NAME = ft_hexdump

CC = cc
CFLAG = -Wall -Wextra -Werror
SRC = ft_hexdump.c ft_print_memory.c no_args.c ft_strcmp.c
HEAD = ./includes/
OBJ= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
