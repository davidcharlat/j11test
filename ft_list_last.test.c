#include <stdlib.h>
#include <stdio.h>
#include "j11/ex04/ft_list.h"

t_list	*ft_create_elem (void *data);
t_list	ft_list_last (t_list *begin_list);

int		main (void)
{
	t_list	*list;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "bye";
	
	printf ("testing ft_list_size\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	printf ("if list's size is 3, and the last data is pointing to the char* 'Bye' ft_list_last.data must be pointing to 'bye'\n");
	if ((ft_list_last (list)).data != data3)
	{
		printf ("error: received %s\n", (char*)(ft_list_last (list)).data);
		return (1);
	}
	printf ("OK\n");
	printf ("ft_list_last : OK\n");
	return (0);
}
