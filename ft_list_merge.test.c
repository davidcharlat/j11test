#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

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

	t_list	*list;
	t_list	*list2;
	t_list	*null;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "good";
	char	data4[] = "bye";
	char	data21[] = "hello";
	char	data22[] = "hello guys";
	int		error = 0;
	
	null = NULL;
	printf ("\ntesting ft_list_merge\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data4);
	list2 = ft_create_elem ((void*)data21);
	list2->next = ft_create_elem ((void*)data22);
	list2->next->next = ft_create_elem ((void*)data3);
	list2->next->next->next = ft_create_elem ((void*)data4);
	ft_list_merge(&list, list2);
	printf ("ft_list_merge must be able to marge list2, which length is 4,  after list which length is 3\n");
	printf("first element\n : expecting 'hello world', received %s\n", (char*)list->data);
	if (!strcmp ("hello world", (char*)list->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("4th element\n : expecting 'hello', received %s\n", (char*)list->next->next->next->data);
	if (!strcmp ("hello", (char*)list->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("last element\n : expecting 'bye', received %s\n", (char*)list->next->next->next->next->next->next->data);
	if (!strcmp ("bye", (char*)list->next->next->next->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("only pointers must have change: list2 must be equal to list->next->next->next\n");
	printf ("expecting %p, received %p\n", (void*)list2, (void*)list->next->next->next);
	if ((void*)list2 == (void*)list->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_merge must run if the second list is empty\n");
	ft_list_merge(&list2, NULL);
	printf ("expecting %p, received %p\n", NULL, (void*)list2->next->next->next->next);
	if (NULL == (void*)list2->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_merge must run if both lists are empty\n");
	ft_list_merge(&null, NULL);
	printf ("expecting %p, received %p\n", NULL, (void*)null);
	if (NULL == (void*)null)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_merge must run if the first list is empty\n");
	ft_list_merge(&null, list2);
	printf ("first element must point at:  expecting %s, received %s\n", "hello", (char*)null->data);
	if (!strcmp ("hello", (char*)null->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	clear(&list);
	if (error)
		return (1);	
	printf("ft_list_merge: OK\n");
	return (0);
}
