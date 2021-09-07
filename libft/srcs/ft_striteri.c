/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:03:44 by lread             #+#    #+#             */
/*   Updated: 2021/09/07 14:03:44 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (str == NULL || f == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		f(i, str + i);
		i++;
	}
}
