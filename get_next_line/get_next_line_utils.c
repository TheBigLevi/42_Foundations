#include "get_next_line.h"

static void	ft_overwrite(char **line, int i, int fd)
{
	int	j;

	j = 0;
	while (i < ft_strlen(line[fd]) && line[fd][i] != '\0')
	{
		line[fd][j] = line[fd][i];
		i++;
		j++;
	}
	line[fd][j] = '\0';
}

char	*ft_trim(char **line, int fd)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (line[fd][i] != '\0')
	{
		str[i] = line[fd][i];
		if (line[fd][i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n' && line[fd][i] != '\0')
	{
		str[i + 1] = '\0';
		ft_overwrite(line, i + 1, fd);
	}
	else
	{
		str[i] = '\0';
	}
	return (str);
}

static int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_readline(int fd, char *buf, char **line)
{
	int		r;
	int		i;

	r = 0;
	i = 0;
	while (ft_strchr(line[fd], '\n') == 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (-1);
		else if (r == 0)
			return (0);
		buf[r] = '\0';
		line[fd] = ft_strjoin(line[fd], buf);
	}
	return (1);
}
