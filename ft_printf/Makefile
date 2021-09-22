SRCS = srcs/ft_flags.c \
		srcs/ft_hex.c \
		srcs/ft_int.c \
		srcs/ft_str.c \
		srcs/ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = libftprintf.a
LIBFT = libft.a

.PHONY: all clean fclean re

%.o: %.c
	$(CC) -c $(CFLAGS) -I includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean:
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(OBJS)

re: fclean all