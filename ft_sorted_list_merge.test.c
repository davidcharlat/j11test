#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_sorted_list_merge (t_list **begin_list1, t_list *begin_list2, int (*cmp)());

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

int 	cmp0(void *data1, void *data2)
{
	return (strcmp((char*)data1, (char*)data2));
}

int 	cmplen(void *data1, void *data2)
{
	return (strlen((char*)data1) - strlen((char*)data2));
}

	t_list	*list;
	t_list	*list2;
	t_list	*copy;
	t_list	*null;
	t_list	*list3;
	t_list	*print;
	char	data65[] = "hello world";
	char	data46[] = "hello everybody";
	char	data22[] = "good";
	char	data11[] = "bye";
	char	data33[] = "hello";
	char	data54[] = "hello guys";
	int		error = 0;
	
	null = NULL;
	printf ("\ntesting ft_sorted_list_merge\n");
	list = ft_create_elem ((void*)data22);
	list->next = ft_create_elem ((void*)data22);
	list->next->next = ft_create_elem ((void*)data33);
	copy = ft_create_elem ((void*)data22);
	copy->next = ft_create_elem ((void*)data33);
	copy->next->next = ft_create_elem ((void*)data65);
	list2 = ft_create_elem ((void*)data11);
	list2->next = ft_create_elem ((void*)data54);
	list2->next->next = ft_create_elem ((void*)data65);
	list2->next->next->next = ft_create_elem ((void*)data46);
	list3 = ft_create_elem ((void*)data11);
	list3->next = ft_create_elem ((void*)data54);
	list3->next->next = ft_create_elem ((void*)data65);
	list3->next->next->next = ft_create_elem ((void*)data46);
ft_sorted_list_merge(&list, list2, &cmplen);
	printf ("ft_sorted_list_merge must be able to merge list2 if its 1st element is 'smaller' than list's 1st element \n");
	printf("first element\n : expecting 'bye', received %s\n", (char*)list->data);
	if (!strcmp ("bye", (char*)list->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("4th element\n : expecting 'hello', received %s\n", (char*)list->next->next->next->data);
	if (!strcmp ("hello", (char*)list->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("last element\n : expecting 'hello everybody', received %s\n", (char*)list->next->next->next->next->next->next->data);
	if (!strcmp ("hello everybody", (char*)list->next->next->next->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("the lastelement->next must point at NULL : expecting 'NULL', received %p\n", (void*)list->next->next->next->next->next->next->next);
	if (NULL == (char*)list->next->next->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_merge must run if the second list is empty\n");
ft_sorted_list_merge(&list, NULL, &cmplen);
	printf ("expecting %p, received %p\n", NULL, (void*)list->next->next->next->next->next->next->next);
	if (NULL == (void*)list->next->next->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_merge must run if both lists are empty\n");
ft_sorted_list_merge(&null, NULL, &cmplen);
	printf ("expecting %p, received %p\n", NULL, (void*)null);
	if (NULL == (void*)null)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_merge must run if the first list is empty\n");
ft_sorted_list_merge(&null, list3, &cmplen);
	printf ("first element must point at:  expecting %s, received %s\n", "bye", (char*)null->data);
	if (!strcmp ("bye", (char*)null->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
ft_sorted_list_merge(&null, copy, &cmplen);
	printf ("ft_sorted_list_merge must be able to merge list2 if its last element is 'smaller' than list's last element \n");
	printf("last element\n : expecting 'hello everybody', received %s\n",(char*)null->next->next->next->next->next->next->data);
	if (!strcmp ("hello everybody", (char*)null->next->next->next->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("4th element\n : expecting 'hello guys', received %s\n", (char*)null->next->next->next->data);
	if (!strcmp ("hello guys", (char*)null->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("the lastelement->next must point at NULL : expecting 'NULL', received %p\n", (void*)null->next->next->next->next->next->next->next);
	if (NULL == (char*)null->next->next->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("last test: merging merged lists\n");
ft_sorted_list_merge(&list, null, &cmplen);
	if (NULL == (char*)list->next->next->next->next->next->next->next->next->next->next->next->next->next->next)
		printf (" last ptr OK\n");
	else
		error = printf("Error\n");
	printf("received :\n");
	print = list;
	while (print)
		{printf("%s\n", (char*)print->data); print = print->next;}
	if (!strcmp ("hello guys", (char*)list->next->next->next->next->next->next->next->data))
		printf ("data OK\n");
	else
		error = printf("Error\n");
	clear(&list);
	if (error)
		return (1);	
	printf("ft_list_merge: OK\n");
	return (0);
}
