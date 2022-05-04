SRCS = main.c philo.c static.c utils.c

OBJS = $(SRCS:.c=.o)

NAME = philo
CC = gcc
CFLAGS = -Werror -Wextra -Wall

.PHONY: all clean fclean re

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all