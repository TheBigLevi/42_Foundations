#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

char 	*get_next_line(int fd);
int		ft_readline(int fd, char *buf, char *line, int buffer);
int		ft_strlen(char *str);

#endif