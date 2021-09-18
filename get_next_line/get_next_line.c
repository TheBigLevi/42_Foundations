#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*line[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (line[fd] == NULL)
	{
		line[fd] = ft_strdup("");
		if (line[fd] == NULL)
			return (NULL);
	}
	r = ft_readline(fd, buf, line);
	if (r < 0)
		return (NULL);
	else if (r > 0)
		return (ft_trim(line, fd));
	return (line[fd]);
}
