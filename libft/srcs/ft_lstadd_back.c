#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	if (alst != NULL && new != NULL)
	{
		node = ft_lstlast(*alst);
		node->next = new;
	}
}
