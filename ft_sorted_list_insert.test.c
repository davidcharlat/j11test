#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

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

int 	cmplen(void *data1, void *data2)
{
	return (strlen((char*)data1) - strlen((char*)data2));
}


	t_list	*list2;
	t_list	*list3;
	t_list	*null;
	t_list	*print;
	char	data65[] = "hello world";
	char	data46[] = "hello everybody";
	char	data22[] = "good";
	char	data11[] = "bye";
	char	data33[] = "hello";
	char	data54[] = "hello guys";
	int		error = 0;
	
	null = NULL;
	printf ("\ntesting ft_sorted_list_insert\n");
	list2 = ft_create_elem ((void*)data11);
	list2->next = ft_create_elem ((void*)data54);
	list2->next->next = ft_create_elem ((void*)data65);
	list2->next->next->next = ft_create_elem ((void*)data65);
	list3 = ft_create_elem ((void*)data33);
	list3->next = ft_create_elem ((void*)data54);
	list3->next->next = ft_create_elem ((void*)data65);
	list3->next->next->next = ft_create_elem ((void*)data46);
ft_sorted_list_insert(&list2, data22, &cmplen);
	printf ("ft_sorted_list_insert must be able to insert in the middle of list \n");
	printf("first element\n : expecting 'bye', received %s\n", (char*)list2->data);
	if (!strcmp ("bye", (char*)list2->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("4th element\n : expecting 'hello world', received %s\n", (char*)list2->next->next->next->data);
	if (!strcmp ("hello world", (char*)list2->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("2nd element\n : expecting 'good', received %s\n", (char*)list2->next->data);
	if (!strcmp ("good", (char*)list2->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("the lastelement->next must point at NULL : expecting 'NULL', received %p\n", (void*)list2->next->next->next->next->next);
	if (NULL == (char*)list2->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_sorted_list_insert must be able to insert in the 1st place \n");
ft_sorted_list_insert(&list3, data22, &cmplen);
	printf("first element\n : expecting 'good', received %s\n", (char*)list3->data);
	if (!strcmp ("good", (char*)list3->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
		printf("the lastelement->next must point at NULL : expecting 'NULL', received %p\n", (void*)list3->next->next->next->next->next);
	if (NULL == (char*)list3->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");	
	printf ("ft_sorted_list_insert must be able to insert in the last place of an allready extended list \n");
ft_sorted_list_insert(&list3, data46, &cmplen);
	printf("last element\n : expecting 'hello everybody', received %s\n", (char*)list3->next->next->next->next->next->data);
	if (!strcmp ("hello everybody", (char*)list3->next->next->next->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
		printf("the lastelement->next must point at NULL : expecting 'NULL', received %p\n", (void*)list3->next->next->next->next->next->next);
	if (NULL == (char*)list3->next->next->next->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");	
	clear(&list2);
	clear(&list3);
	if (error)
		return (1);	
	printf("ft_list_insert: OK\n");
	return (0);
}
