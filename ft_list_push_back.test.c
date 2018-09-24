#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex01/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_push_back (t_list **begin_list, void *data);

int		main (void)
{
	t_list	*list;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	void 	*mem;
	
	printf ("testing ft_list_push_back\n");
	list = ft_create_elem ((void*)data1);
	mem = (void*)&list;
	ft_list_push_back (&list, (void*)data2);
	printf ("expecting 1st *data pointing at 'hello world' and 2nd at 'hello everybody'\n");
	printf ("1st: %s\n", (char*)list->data);
	printf ("2nd: %s\n", (char*)list->next->data);
	if (!strcmp("hello world", (char*)list->data) && !strcmp("hello everybody", (char*)list->next->data))
	{
		printf ("OK\n");
		printf ("the last element must point at NULL\n");
		if (!(char*)list->next->next)
		{
			printf("OK\n");
			printf("*begin_list musn't have changed\n");
			if (mem == (void*)&list)
			{
				printf("OK\n");
				printf("ft_list_push_back: OK\n");
				return (0);
			}	
		}
	}
	printf ("error\n");
	return (1);
}
