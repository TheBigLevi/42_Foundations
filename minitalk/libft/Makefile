SRCS = srcs/ft_isalpha.c \
		srcs/ft_isdigit.c \
		srcs/ft_isalnum.c \
		srcs/ft_isascii.c \
		srcs/ft_isprint.c \
		srcs/ft_strlen.c \
		srcs/ft_memset.c \
		srcs/ft_bzero.c \
		srcs/ft_memcpy.c \
		srcs/ft_memmove.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlcat.c \
		srcs/ft_toupper.c \
		srcs/ft_tolower.c \
		srcs/ft_strchr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strncmp.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_strnstr.c \
		srcs/ft_atoi.c \
		srcs/ft_calloc.c \
		srcs/ft_strdup.c \
		srcs/ft_substr.c \
		srcs/ft_strjoin.c \
		srcs/ft_strtrim.c \
		srcs/ft_split.c \
		srcs/ft_itoa.c \
		srcs/ft_strmapi.c \
		srcs/ft_striteri.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

BONUS 	= bonus/ft_lstnew.c \
		bonus/ft_lstadd_front.c \
		bonus/ft_lstsize.c \
		bonus/ft_lstlast.c \
		bonus/ft_lstadd_back.c \
		bonus/ft_lstdelone.c \
		bonus/ft_lstclear.c \
		bonus/ft_lstmap.c \
		bonus/ft_lstiter.c

OBJS_B = $(BONUS:.c=.o)

CC 	= gcc
CFLAGS = -Werror -Wextra -Wall
NAME = libft.a

.PHONY: bonus all clean fclean re

%.o: %.c
		${CC} -c $(CFLAGS) -I includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

bonus:  $(OBJS) $(OBJS_B)
		ar -rcs $(NAME) $(OBJS) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
		rm -f $(NAME)

re: fclean all