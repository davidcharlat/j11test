#include <stdlib.h>
#include <stdio.h>
#include "j11/ex00/ft_list.h"

t_list	*ft_create_elem (void *data);

int		main (void)
{
	void	*ptr;
	t_list	*list;
	char	data[] = "hello world";
	
	printf ("testing ft_create_elem\n");
	ptr = (void*)data;
	if (list = ft_create_elem (ptr));
	{
		if (list->data != ptr)
		{
			printf ("error : list->data isn't equal to the provided parameter; expected %p, received %p", ptr, list->data);
			return (2);
		}
		if (list->next)
		{
			printf ("error : list->next isn't NULL; received %p", list->data);
			return (3);
		}
		printf ("list->data: expected %p (pointing on string 'hello world'), received %p (%s) :OK\nlist->next, received NULL :OK\n", ptr, list->data, (char*)list->data);
		printf ("ft_create_elem.c OK\n");
		return (0);
	}
	printf ("error: failed to run ft_create_elem (ptr)");
	return (4);
}
