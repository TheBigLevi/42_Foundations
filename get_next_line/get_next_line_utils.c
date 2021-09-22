/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:37:24 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 18:37:24 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	if (buf == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buf) + 1));
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	while (buf[j] != '\0')
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	free(line);
	return (str);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	if (str == NULL)
		return (0);
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

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}
