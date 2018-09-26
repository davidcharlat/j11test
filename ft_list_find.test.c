#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

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

int 	cmp0(void *data1, void *data2)
{
	return (strcmp((char*)data1, (char*)data2));
}

int 	do_not_cmp(void *data1, void *data2)
{
	return (3);
}

int 	cmp6(void *data1, void *data2)
{
	return (strncmp((char*)data1, (char*)data2, 6));
}

	t_list	*list;
	t_list	*result;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "good";
	char	data4[] = "bye";
	char	data_ref[] = "hello everybody";
	
	printf ("testing ft_find\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);
	result = ft_list_find(list, &data_ref, &cmp0);
	printf ("in all test, data_ref will point at 'hello everybody'\nif list->next->data is the first element that points at 'hello everybody' and (*cmp) = strcmp, ft_list_find()->data must point at 'hello everybody '\n");
	printf ("received %s\n", (char*)result->data);
	if (!strcmp("hello everybody", (char*)result->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		return (1);
	}
	printf ("then the 2nd element of the returned list must be the third of the initial list : 'good'\n");
	printf ("received %s\n", (char*)result->next->data);
	if (!strcmp("good", (char*)result->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		return (1);
	}
	printf (" if list->data is pointing at 'hello world',  and (*cmp) compares only the 6 firsts chars, result->data must point at 'hello world'\n");
	result = ft_list_find(list, &data_ref, &cmp6);
	printf ("received %s\n", (char*)result->data);
	if (!strcmp("hello world", (char*)result->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);

		return (1);
	}
	printf ("if (*cmp) is so that no element of the list matches, ft_list_find must return NULL\n");
	result = ft_list_find(list, &data_ref, &do_not_cmp);
	printf ("received %p\n", (char*)result);
	if (!result)
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);

		return (1);
	}
	clear(&list);
	printf("ft_list_find: OK\n");
	return (0);
}
