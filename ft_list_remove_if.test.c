#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_remove_if (t_list **begin_list, void *data_ref, int (*cmp)());

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

int 	cmp4(void *data1, void *data2)
{
	return (strncmp((char*)data1, (char*)data2, 4));
}

	t_list	*list;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;
	t_list	*list5;
	t_list	*copy;
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "good";
	char	data4[] = "bye";
	char	data21[] = "hello world";
	char	data22[] = "hello everybody";
	char	data23[] = "good";
	char	data24[] = "bye";
	char	data31[] = "hello world";
	char	data32[] = "hello everybody";
	char	data33[] = "good";
	char	data34[] = "bye";
	char	data_ref[] = "hello everybody";
	int		error = 0;
	
	printf ("testing ft_list_remove_if\n");
	list = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);
	list2 = ft_create_elem ((void*)data21);
	list2->next = ft_create_elem ((void*)data22);
	list2->next->next = ft_create_elem ((void*)data23);
	list2->next->next->next = ft_create_elem ((void*)data24);
	list3 = ft_create_elem ((void*)data31);
	list3->next = ft_create_elem ((void*)data32);
	list3->next->next = ft_create_elem ((void*)data33);
	list3->next->next->next = ft_create_elem ((void*)data34);
	list4 = ft_create_elem ((void*)data31);
	list4->next = ft_create_elem ((void*)data32);
	list4->next->next = ft_create_elem ((void*)data34);
	list4->next->next->next = ft_create_elem ((void*)data34);
	list5 = ft_create_elem ((void*)data31);
	list5->next = ft_create_elem ((void*)data33);
	list5->next->next = ft_create_elem ((void*)data33);
	list5->next->next->next = ft_create_elem ((void*)data32);
	copy = ft_create_elem ((void*)data1);
	copy->next = ft_create_elem ((void*)data2);
	copy->next->next = ft_create_elem ((void*)data3);
	copy->next->next->next = ft_create_elem ((void*)data4);
	ft_list_remove_if(&list, &data_ref, &cmp0);
	printf ("if data_ref and only list->next->data point at 'hello everybody', and (*cmp) = strcmp, only the 2nd elt must've been removed\n");
	printf("first element\n : expecting 'hello world', received %s\n", (char*)list->data);
	if (!strcmp ("hello world", (char*)list->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("2nd element\n : expecting 'good', received %s\n", (char*)list->next->data);
	if (!strcmp ("good", (char*)list->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_remove_if must be able to remove both first and second elements if necessary\n");
	ft_list_remove_if(&list2, &data_ref, &cmp4);
	printf("first element\n : expecting 'good', received %s\n", (char*)list2->data);
	if (!strcmp ("good", (char*)list2->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("ft_list_remove_if must be able to remove the last element if necessary\n");
	ft_list_remove_if(&list3, &data4, &cmp0);
	printf("last element\n : expecting 'good', received %s\n", (char*)list3->next->next->data);
	if (!strcmp ("good", (char*)list3->next->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("then the last '->next' must point at NULL\n");
	printf("last 'next'\n : expecting 'NULL', received %p\n", (void*)list3->next->next->next);
	if (!(void*)list3->next->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
		
	printf ("ft_list_remove_if must be able to remove the 2 consecutive elements if necessary\n");
	ft_list_remove_if(&list5, &data3, &cmp0);
	printf("2nd element\n : expecting 'hello everybody', received %s\n", (char*)list5->next->data);
	if (!strcmp ("hello everybody", (char*)list5->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
		
	printf ("ft_list_remove_if must be able to remove the 2 last elements if necessary\n");
	ft_list_remove_if(&list4, &data4, &cmp0);
	printf("last element\n : expecting 'hello everybody', received %s\n", (char*)list4->next->data);
	if (!strcmp ("hello everybody", (char*)list4->next->data))
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf("then the last '->next' must point at NULL\n");
	printf("last 'next'\n : expecting 'NULL', received %p\n", (void*)list4->next->next);
	if (!(void*)list4->next->next)
		printf ("OK\n");
	else
		error = printf("Error\n");
	printf ("if every elements have to be removed, ft_list_remove_if must make begin_list point at NULL\n");
	ft_list_remove_if(&copy, &data4, &do_not_cmp);
	printf("expecting 'NULL', received %p\n", (void*)copy);
	if (!(void*)copy)
		printf ("OK\n");
	else
		error = printf("Error\n");
	clear(&list);
printf ("list ");
	clear(&copy);
printf ("copy ");
	clear(&list2);
printf ("list2 ");
	clear(&list3);
printf ("list3\n");
	if (error)
		return (1);	
	printf("ft_list_remove_if: OK\n");
	return (0);
}
