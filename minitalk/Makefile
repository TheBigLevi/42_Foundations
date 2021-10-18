SRCS_SERVER = minitalk_server.c
SRCS_CLIENT = minitalk_client.c

CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./libft
	$(MAKE) server client
	cp libft/libft.a $(NAME)

server:
	$(CC) $(CFLAGS) -I libft/includes libft/libft.a $(SRCS_SERVER) -o server.out

client:
	$(CC) $(CFLAGS) -I libft/includes libft/libft.a $(SRCS_CLIENT) -o client

clean:
	$(MAKE) clean -C ./libft
	rm -f server client

fclean:
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) server client

re: fclean all