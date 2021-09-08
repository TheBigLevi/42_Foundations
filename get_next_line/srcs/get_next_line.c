#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		r;
	static char *line;

	if (fd < 0 || BUFF_SIZE < 1)
		return (NULL);
	if (line == NULL)
	{
		line = (char *)malloc(sizeof(char) * 1);
		if (line == NULL)
			return (NULL);
		line[0] = '\0';
	}
	if (ft_strlen(line) == 0)
		r = ft_readline(fd, buf, line, BUFF_SIZE);
	else
		r = ft_readline(fd, buf, line, BUFF_SIZE - ft_strlen(line));
	if (r < 0)
		return (NULL);
	else if (r > 0);
		return (ft_strtrim(line));
	return (line);
}
