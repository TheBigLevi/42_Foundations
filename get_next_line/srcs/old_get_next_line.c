//#include "get_next_line.h"

int	ft_readbuf(int const fd, unsigned int index, char *buf)
{
	static int check;

	check = -2;
	if (index == BUFF_SIZE - 1 || check == -2)
	{
		check = read(fd, buf, BUFF_SIZE);
	}
	return (check);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;	
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_strchr(const char *str, int c)
{
	unsigned int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (0);
	return (1);
}


int	get_next_line(int const fd)
{
	int			r;
	char 		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*line;
	
	r = 1;
	if (fd < 0 || line != NULL || BUFF_SIZE <= 0)
		return (-1);
	line = (char *)malloc(sizeof(char) * 1);
	if (line == NULL)
		return (-1);
	else
		line[0] = 0;
	while (ft_strchr(line, '\n') == 1)
	{
		r = ft_readbuf(fd, buf);
		if (r <= 0)
			break ;
		buf[BUFF_SIZE] = '\0';
		tmp = ft_strjoin(line, buf);
		if (tmp == NULL)
			return (-1);
		free(line);
		line = tmp;
	}
	if (r == 0)
		*line = ft_strdup(line);
	else if (r > 0)
		//*line = ft_strdup()
}