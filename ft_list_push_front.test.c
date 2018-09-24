#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex01/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_push_front (t_list **begin_list, void *data);

int		main (void)
{
	t_list	*list;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	
	printf ("testing ft_list_push_front\n");
	list = ft_create_elem ((void*)data1);
	ft_list_push_front (&list, (void*)data2);
	printf ("expecting 1st *data pointing at 'hello everybody' and 2nd at 'hello world'\n");
	printf ("1st: %s\n", (char*)list->data);
	printf ("2nd: %s\n", (char*)list->next->data);
	if (!strcmp("hello everybody", (char*)list->data) && !strcmp("hello world", (char*)list->next->data))
	{
		printf ("OK\n");
		printf ("the last element must point at NULL\n");
		if (!(char*)list->next->next)
		{
			printf("OK\n");
			printf("ft_list_push_front: OK\n");
			return (0);
		}
	}
	printf ("error\n");
	return (1);
}
