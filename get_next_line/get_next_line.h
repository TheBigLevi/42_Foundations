#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_readline(int fd, char *buf, char **line);
char	*ft_trim(char **line, int fd);
char	*ft_strdup(char *str);

#endif