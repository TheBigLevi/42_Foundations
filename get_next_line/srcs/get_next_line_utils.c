#include "get_next_line.h"


static char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

void	ft_overwrite(char *line, int i, int *j)
{
	while (line[i] != '\0')
	{
		line[*j] = line[i];
		i++;
		*j += 1;
	}
}

char	*ft_strtrim(char *line, char c)
{
	int i;
	int j;
	char *str;
	char *tmp;
	
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		str[i] = line[i];
		if (line[i + 1] == '\n')
		{
			str[i + 1] = '\n';
			str[i + 2] = '\0';
			break ;
		}
		else if (line[i + 1] == '\0')
		{
			str[i + 1] = '\0';
			break ;
		}
		i++;
	}
	ft_overwrite(line, i, &j);
	line[j] = '\0';
	return (str);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i] != '\0')
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_readline(int fd, char *buf, char *line, int buffer)
{
	int		r;
	char	*tmp;

	while (ft_strchr(line, '\n') == NULL)
	{
		r = read(fd, buf, BUFF_SIZE);
		if (r < 0)
			return (-1);
		else if (r == 0)
			return (0);
		buf[BUFF_SIZE] = '\0';
		tmp = ft_strjoin(line, buf);
		if (tmp == NULL)
			return (-1);
		free (line);
		line = tmp;
	}
	return (1);
}
