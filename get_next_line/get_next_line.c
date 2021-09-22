/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:37:24 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 18:37:24 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_append(char *line, char *buf)
{
	if (line == NULL)
		return (ft_strdup(buf));
	else
		return (ft_strjoin(line, buf));
}

static char	*ft_overwrite(char *line)
{
	int		i;
	int		j;
	char	*str;

	if (ft_strchr(line, '\n') == 0)
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	while (i + j < ft_strlen(line) && line[i + j] != '\0')
	{
		str[j] = line[i + j];
		j++;
	}
	str[j] = '\0';
	free(line);
	return (str);
}

static char	*ft_trim(char *line)
{
	int		i;
	int		j;
	char	*str;

	if (line == NULL || line[0] == '\0')
		return (NULL);
	else if (ft_strchr(line, '\n') == 0)
		return (ft_strdup(line));
	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (line[j] != '\0')
	{
		str[j] = line[j];
		if (line[j++] == '\n')
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*buf;
	ssize_t		r;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	r = 1;
	while (ft_strchr(line[fd], '\n') == 0 && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			break ;
		buf[r] = '\0';
		line[fd] = ft_append(line[fd], buf);
	}
	free(buf);
	buf = ft_trim(line[fd]);
	line[fd] = ft_overwrite(line[fd]);
	return (buf);
}
