#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

void	davidcharlat_list_clear(t_list **begin_list)
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

int		main (void)
{
	t_list	*list;
	t_list	*list2;
	t_list	*result;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "bye";
	char	data4[] = "bye";
	
	printf ("testing ft_list_at\n");
	list = ft_create_elem ((void*)data1);
	list2 = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);

	printf ("As list's length is 4 and nbr is 2, ft_list_at must return the 2nd element.\n");
	result = ft_list_at(list, 2);
	printf ("2nd element.next = %p\n", (void*)list->next->next);
	printf ("result->next = %p\n", (void*)result->next);
	if ((void*)list->next->next == (void*)result->next)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("2nd element.data = %s\n", (char*)list->next->data);
	printf ("result->data = %s\n", (char*)result->data);
	if (!strcmp((char*)list->next->data, (char*)result->data))
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("As list's length is 4 and nbr is 4, ft_list_at must return the 4th element.\n");
	result = ft_list_at(list, 4);
	printf ("4th element.next = %p\n", (void*)list->next->next->next->next);
	printf ("result->next = %p\n", (void*)result->next);
	if ((void*)list->next->next->next->next == (void*)result->next)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("4th element.data = %s\n", (char*)list->next->next->next->data);
	printf ("result->data = %s\n", (char*)result->data);
	if (!strcmp((char*)list->next->next->next->data, (char*)result->data))
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("As list's length is 4 and nbr is 1, ft_list_at must return the 1st element.\n");
	result = ft_list_at(list, 1);
	if ((void*)list == (void*)result)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("As list's length is 4 and nbr is 0, ft_list_at must return a pointer to NULL.\n");
	result = ft_list_at(list, 0);
	if (NULL == (void*)result)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("As list's length is 4 and nbr is 5, ft_list_at must return a pointer to NULL.\n");
	result = ft_list_at(list, 5);
	if (NULL == (void*)result)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("As list's length is 1 and nbr is 2, ft_list_at must return a pointer to NULL.\n");
	result = ft_list_at(list2, 2);
	if (NULL == (void*)result)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf ("As list's length is 1 and nbr is 1, ft_list_at must return the only element.\n");
	result = ft_list_at(list2, 1);
	if ((void*)list2 == (void*)result)
		printf ("OK\n");
	else
	{
		printf ("Error\n");
		return (1);
	}
	printf("free lists used for tests :");
	davidcharlat_list_clear(&list);
	davidcharlat_list_clear(&list2);
	printf("OK\nft_list_at: OK\n");
	return (0);
}
