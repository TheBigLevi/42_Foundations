/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:38:42 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 18:38:42 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	*ft_strdup(char *str);
int		ft_strchr(char *str, int c);
int		ft_strlen(char *str);

#endif
