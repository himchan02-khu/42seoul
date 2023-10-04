NAME = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror
SRCD = ./srcs/
SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = ${addprefix $(SRCD), $(SRC)}
OBJS= $(patsubst %.c, %.o, $(SRCS))
HEAD = ./includes/
AR = ar -cr

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEAD)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
