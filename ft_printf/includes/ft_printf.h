/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:42:42 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 20:42:42 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		count;
}			t_print;

int		ft_printf(const char *str, ...);
void	ft_flags(t_print *table, const char *str);
void	ft_hex(t_print *table, char c);
void	ft_ptr(t_print *table);
void	ft_signed(t_print *table);
void	ft_unsigned(t_print *table);
void	ft_chr(t_print *table);
void	ft_str(t_print *table);

#endif
