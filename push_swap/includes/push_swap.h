#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	usage(int n);
int		convert_num(char *num);
t_list	*mk_lst(int argc, char *argv[]);

#endif