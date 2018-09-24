#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

int		main (void)
{

void	clear(t_list **begin_list)
{
	t_list	*addr_next;
	t_list	*to_free;
	
	to_free = *begin_list;
	*begin_list = NULL;
	addr_next = to_free->next;
	free ((void*)to_free);
	while ((void*)addr_next != NULL)
	{
		to_free = addr_next;
		addr_next = addr_next->next;
		(*to_free).next = NULL;
		free ((void*)to_free);
	}
}

void	e_into_z (void* data)
{
	int 	i;
	char	*datachar;
	
	datachar = (char*)data;
	i = 0;
	while (datachar[i])
	{
		if (datachar[i] == 'e')
			datachar[i] = 'z';
		i++;
	}
}
	t_list	*list;
	t_list	*copy;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "good";
	char	data4[] = "bye";
	
	printf ("testing ft_list_foreach\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);
	copy = ft_create_elem ((void*)data1);
	copy->next = ft_create_elem ((void*)data2);
	copy->next->next = ft_create_elem ((void*)data3);
	copy->next->next->next = ft_create_elem ((void*)data4);
	ft_list_foreach(list, &e_into_z);
	printf ("testing with list's length = 4\n");
	printf ("f change 'e' into 'z'\n");
	printf ("list->data was pointing at a pointer to 'hello world',  the char* must have change\n");
	printf ("received %s\n", (char*)list->data);
	if (!strcmp("hzllo world", (char*)list->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
	    clear(&copy);
		return (1);
	}
	printf ("another list named copy was pointing to the same char* as 'list'.\ncopy->next->next->next->data was pointing at a pointer to 'bye'\nthe char* must have changed\n");
	printf ("received %s\n", (char*)copy->next->next->next->data);
	if (!strcmp("byz", (char*)copy->next->next->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		clear(&list);
	    clear(&copy);
		return (1);
	}
	clear(&copy);
	clear(&list);
	printf("ft_list_foreach: OK\n");
	return (0);
}
