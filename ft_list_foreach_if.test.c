#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j11/ex07/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_foreach_if (t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

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

int 	do_not_cmp(void *data1, void *data2)
{
	return (17);
}

int 	cmp0(void *data1, void *data2)
{
	return (strcmp((char*)data1, (char*)data2));
}

int 	cmp18(void *data1, void *data2)
{
	return (strcmp((char*)data1, (char*)data2) + 18);
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
	t_list	*list2;
	t_list	*list3;
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
	
	printf ("testing ft_list_foreach_if\n");
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
	copy = ft_create_elem ((void*)data1);
	copy->next = ft_create_elem ((void*)data2);
	copy->next->next = ft_create_elem ((void*)data3);
	copy->next->next->next = ft_create_elem ((void*)data4);
	ft_list_foreach_if(list, &e_into_z, &data_ref, &cmp0);
	printf ("in all test, data_ref will point at 'hello everybody' and f change 'e' into 'z'\nif list->next->data point at 'hello everybody' and (*cmp) = strcmp, the char* must have changed into 'hzllo zvzrybody'\n");
	printf ("received %s\n", (char*)list->next->data);
	if (!strcmp("hzllo zvzrybody", (char*)list->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	printf ("list->data was pointing at a pointer to 'hello world',  the char* mustn't have change\n");
	printf ("received %s\n", (char*)list->data);
	if (!strcmp("hello world", (char*)list->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	printf ("another list named copy was pointing to the same char* as 'list'.\nthe chenges must have affect 'copy'\n");
	printf ("received %s\n", (char*)copy->next->data);
	if (!strcmp("hzllo zvzrybody", (char*)copy->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	ft_list_foreach_if(list2, &e_into_z, &data_ref, &do_not_cmp);
	printf ("if list2->next->data points at 'hello everybody' and (*cmp)consider every void* equivalent, returning the same value with any 'void*'   , the char* must have changed into 'hzllo zvzrybody'\n");
	printf ("received %s\n", (char*)list2->next->data);
	if (!strcmp("hzllo zvzrybody", (char*)list2->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	printf ("list2->data was pointing at a pointer to 'hello world',  the char* must have changed into 'hzllo world'\n");
	printf ("received %s\n", (char*)list2->data);
	if (!strcmp("hzllo world", (char*)list2->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	ft_list_foreach_if(list3, &e_into_z, &data_ref, &cmp18);
	printf ("only void* prooving the same equivalence level with (*cmp) must have changed\n");
	printf ("list3->next->data expecting 'hzllo zvzrybody' received '%s'\n", (char*)list3->next->data);
	if (!strcmp("hzllo zvzrybody", (char*)list3->next->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	printf ("list3->data expecting 'hello world' received '%s'\n", (char*)list3->data);
	printf ("received %s\n", (char*)list3->data);
	if (!strcmp("hello world", (char*)list3->data))
		printf ("OK\n");
	else
	{
		printf ("Error");
		clear(&list);
		clear(&list2);
		clear(&list3);
	    clear(&copy);
		return (1);
	}
	clear(&copy);
	clear(&list);
	clear(&list2);
	clear(&list3);
	printf("ft_list_foreach_if: OK\n");
	return (0);
}
