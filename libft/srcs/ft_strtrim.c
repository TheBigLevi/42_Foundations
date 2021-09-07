/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:03:44 by lread             #+#    #+#             */
/*   Updated: 2021/09/07 14:03:44 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(set, str[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_end(char const *str, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, str[len - i]) == 0)
			break ;
		i++;
	}
	return (len - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
