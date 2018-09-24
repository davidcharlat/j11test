#include <stdlib.h>
#include <stdio.h>
#include "j11/ex05/ft_list.h"

t_list	*ft_create_elem (void *data);
t_list	*ft_list_push_params(int ac, char **av);

int		main (int ac, char **av)
{
	t_list	*list;
	if (ac == 4)
	{
		printf ("testing ft_list_push params with 'hello', 'good' and 'bye' as arg\n");
		list = ft_list_push_params (ac, av);
		printf ("list->data must be pointing at the last arg\n");
		if ((char*)(list->data) != (char*)av[3])
		{
			printf ("error: received %s, expecting %s\n", (char*)(list->data), av[3]);
			return (1);
		}
		printf ("received %s, expecting %s\n", (char*)(list->data), av[3]);
		printf ("OK\n");
		printf ("list->next->next->data must be pointing at av[1]\n");
		if ((char*)(list->next->next->data) != (char*)av[1])
		{
			printf ("error: received %s, expecting %s\n", (char*)(list->next->next->data), av[1]);
			return (1);
		}
		printf ("received %s, expecting %s\n", (char*)(list->next->next->data), av[1]);
		printf ("OK\n");
		printf ("list->next->next->next-> must be pointing at NULL\n");
		if ((void*)(list->next->next->next->next) != (void*)0)
		{
			printf ("error: received %p, expecting NULL", (void*)(list->next->next->next->next));
			return (1);
		}
		printf ("OK\n");
		return (0);
	}
	else
	{
		printf ("testing ft_list_push params without arg\n");
		list = ft_list_push_params (ac, av);
		printf ("OK\n");
		printf ("ft_list_push_params : OK\n");
		return (0);
	}
	return (1);
}
