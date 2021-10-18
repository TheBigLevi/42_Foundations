#include "push_swap.h"
#include <stdio.h>

static void ft_printlst(t_list *node)
{
	// t_list	*node;

	// node = head;
	while (node->next != NULL)
	{
		printf("&&&%d\n", *(int *)node->content);
		node = node->next;
	}
}

t_list	*mk_lst(int argc, char *argv[])
{
	t_list	*head;
	t_list	node;
	int		i;
	int		num;
	void	*ptr;

	num = convert_num(argv[0]);
	ptr = &num;
	head = ft_lstnew(ptr);
	node = *head;
	i = 0;
	while (i < argc)
	{
		num = convert_num(argv[i]);
		ptr = &num;
		printf("---%d\n", *(int *)ptr);
		ft_lstadd_back(&head, ft_lstnew(ptr));
		printf("***%d\n", *(int *)head->content);
		i++;
	}
	ft_printlst(head);
	return (head);
}