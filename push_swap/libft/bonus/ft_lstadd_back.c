/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:04:01 by lread             #+#    #+#             */
/*   Updated: 2021/09/07 14:04:01 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	if (*alst != NULL && alst != NULL)
	{
		node = ft_lstlast(*(alst));
		node->next = new;
		write(1, "Bitc2h", 6);
	}
	else
	{
		write(1, "Bitch", 6);
		*alst = new;
	}
}
