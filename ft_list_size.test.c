#include <stdlib.h>
#include <stdio.h>
#include "j11/ex01/ft_list.h"

t_list	*ft_create_elem (void *data);
int		ft_list_size (t_list *begin_list);

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
	printf ("if list's size is 3, ft_list_size() must return 3\n");
	if (ft_list_size (list) != 3)
	{
		printf ("error: received %d\n", ft_list_size (list));
		return (1);
	}
	printf ("OK\nif list's size is 0, ft_list_size() must return 0\n");
	if (ft_list_size (list->next->next->next))
	{
		printf ("error: received %d\n", ft_list_size (list->next->next->next));
		return (1);
	}
	printf ("OK\n");
	printf ("ft_list_size : OK\n");
	return (0);
}
