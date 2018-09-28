#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_sort (t_list **begin_list, int (*cmp)());

int		main (void)
{

void	clear(t_list **begin_list)
{
	t_list	*addr_next;
	t_list	*to_free;
	
	if (*begin_list)
	{
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
}

int 	do_not_cmp(void *data1, void *data2)
{
	return (0);
}

int 	cmp0(void *data1, void *data2)
{
	return (strcmp((char*)data1, (char*)data2));
}

int 	cmplen(void *data1, void *data2)
{
	return (strlen((char*)data1) - strlen((char*)data2));
}

	t_list	*list;
	t_list	*copy;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "good";
	char	data4[] = "bye";
	char	data5[] = "hi";
	t_list	*null;
	int		error = 0;
	
	null = NULL;
	printf ("\ntesting ft_list_sort\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);
	list->next->next->next->next = ft_create_elem ((void*)data5);
	/*copy = ft_create_elem ((void*)data1);
	copy->next = ft_create_elem ((void*)data2);
	copy->next->next = ft_create_elem ((void*)data3);
	copy->next->next->next = ft_create_elem ((void*)data4);
	copy->next->next->next->next = ft_create_elem ((void*)data5)*/;
	ft_list_sort (&list, &cmp0);
	printf ("if (*cmp) = strcmp, list must now be ordered by ascii \n");
	printf("first element : expecting 'bye', received %s\n", (char*)list->data);
	if (!strcmp ("bye", (char*)list->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("2nd element : expecting 'good', received %s\n", (char*)list->next->data);
	if (!strcmp ("good", (char*)list->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_sort must be able to change the last element of list\nIf cmp compare *data length\n");
	ft_list_sort(&list, &cmplen);
	printf("first element : expecting 'hi', received %s\n", (char*)list->data);
	if (!strcmp ("hi", (char*)list->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("2nd element : expecting 'bye', received %s\n", (char*)list->next->data);
	if (!strcmp ("bye", (char*)list->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("5th element : expecting 'hello everybody', received %s\n", (char*)list->next->next->next->next->data);
	if (!strcmp ("hello everybody", (char*)list->next->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("the last element.next must be pointing at NULL, \nreceived %p\n", (void*)list->next->next->next->next->next);
	if (NULL == (void*)list->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("if *begin_list is NULL, ft_list_sort must do nothing\n");
	ft_list_sort(&null, &cmp0);
	printf ("OK\n");
	clear(&list);
	if (error)
		return (1);	
	printf("ft_list_sort: OK\n");
	return (0);
}
