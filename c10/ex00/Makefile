NAME = ft_display_file

CC = cc
CFLAG = -Wall -Wextra -Werror
SRC = ft_display_file.c
OBJ= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
