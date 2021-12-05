#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int 			value;
	struct s_stack	*next;
}				t_stack;

void	usage(int n);
int		convert_num(char *num);
t_stack	*mk_lst(int argc, char *argv[]);
t_stack *insert_at_head(t_stack **head, t_stack *node);
t_stack *mk_node(int value);

#endif