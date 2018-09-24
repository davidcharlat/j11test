#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	*ft_list_reverse(t_list **begin_list);

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

	t_list	*list;
	t_list	*copy;
	t_list	*test;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "good";
	char	data4[] = "bye";
	
	printf ("testing ft_list_reverse\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);
	copy = ft_create_elem ((void*)data1);
	copy->next = ft_create_elem ((void*)data2);
	copy->next->next = ft_create_elem ((void*)data3);
	copy->next->next->next = ft_create_elem ((void*)data4);
	ft_list_reverse(&list);
	printf ("testing with list's length = 4\n");
	printf ("1st element.data was %s\n", (char*)copy->data);
	printf ("it now must be %s\n", (char*)copy->next->next->next->data);
	if (!strcmp((char*)copy->next->next->next->data, (char*)list->data))
		printf ("OK\n");
	else
	{
		printf ("Error: expected %s, received %s\n",(char*)copy->next->next->next->data, (char*)list->data);
		clear(&list);
	    clear(&copy);
		return (1);
	}
	printf ("2nd element.data was %s\n", (char*)copy->next->data);
	printf ("it now must be %s\n", (char*)copy->next->next->data);
	if (!strcmp((char*)copy->next->next->data, (char*)list->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error: expected %s, received %s\n",(char*)copy->next->next->data, (char*)list->next->data);
		clear(&list);
	 	clear(&copy);
		return (1);
	}
	printf ("3rd element.data was %s\n", (char*)copy->next->next->data);
	printf ("it now must be %s\n", (char*)copy->next->data);
	if (!strcmp((char*)list->next->next->data, (char*)copy->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error: expected %s, received %s\n",(char*)copy->next->data, (char*)list->next->next->data);
		clear(&list);
		clear(&copy);
		return (1);
	}
	printf ("4th element.data was %s\n", (char*)copy->next->next->next->data);
	printf ("it now must be %s\n", (char*)copy->data);
	if (!strcmp((char*)list->next->next->next->data, (char*)copy->data))
		printf ("OK\n");
	else
	{
		printf ("Error: expected %s, received %s\n",(char*)copy->data, (char*)list->next->next->next->data);
		clear(&list);
		clear(&copy);
		return (1);
	}
	printf ("if list's length is 1, ft_list_reverse musn't change anything\n");
	test = ft_create_elem ((void*)data1);
	ft_list_reverse(&test);
	if ((!strcmp((char*)test->data, (char*)copy->data)) && (test->next == NULL))
		printf ("OK\n");
	else
	{
		printf ("Error: reveiced %s and %p, expected %s and %p\n",(char*)copy->data, (void*)copy->next, (char*)test->data, NULL);
		clear(&list);
		clear(&test);
		clear(&copy);
		return (1);
	}
	clear(&list);
	clear(&test);
	clear(&copy);
	printf("ft_list_reverse: OK\n");
	return (0);
}
