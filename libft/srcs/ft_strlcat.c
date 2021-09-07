/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:03:44 by lread             #+#    #+#             */
/*   Updated: 2021/09/07 14:03:44 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_strlen(dst);
	j = 0;
	if (n == 0)
		len = ft_strlen(src);
	else if (n < ft_strlen(dst))
		len = ft_strlen(src) + n;
	else
		len = ft_strlen(src) + ft_strlen(dst);
	while (src[j] != '\0' && i < n - 1 && n != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len);
}
