#include "push_swap.h"

static void	ft_printlst(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

t_stack	*insert_at_head(t_stack **head, t_stack *node)
{
	node->next = *head;
	*head = node;
	return (node);
}

t_stack	*mk_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*mk_lst(int argc, char *argv[])
{
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*tail;
	int		i;

	head = NULL;
	i = 0;
	while (i < argc)
	{
		tmp = mk_node(convert_num(argv[i]));
		if (i == 0)
		{
			insert_at_head(&head, tmp);
			tail = head;
		}
		tail->next = tmp;
		tail = tail->next;
		i++;
	}
	ft_printlst(head);
	return (head);
}
