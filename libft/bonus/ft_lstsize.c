#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}
