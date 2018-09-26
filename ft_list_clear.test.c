#include <stdlib.h>
#include <stdio.h>
#include "j11/ex01/ft_list.h"

t_list	*ft_create_elem (void *data);
void	ft_list_clear (t_list **begin_list);

int		main (void)
{
	t_list	*list;
	t_list	*list2;
	t_list	*mem1;
	t_list	*mem2;
	t_list	*mem3;
	t_list	*mem4;
	t_list	rmem[4];
	char	data1[] = "hello world";
	char	data2[] = "hello everybody";
	char	data3[] = "bye";
	char	data4[] = "bye";
	t_list	*null;
	
	null = NULL;
	printf ("testing ft_list_clear\n");
	list = ft_create_elem ((void*)data1);
	list2 = ft_create_elem ((void*)data1);
	list->next = ft_create_elem ((void*)data2);
	list->next->next = ft_create_elem ((void*)data3);
	list->next->next->next = ft_create_elem ((void*)data4);
	mem1 = (list);
	mem2 = (list->next);
	mem3 = (list->next->next);
	mem4 = (list->next->next->next);
	rmem[0] = *mem1;
	rmem[1] = *mem2;
	rmem[2] = *mem3;
	rmem[3] = *mem4;
	printf ("ft_list_clear 'd better make every pointer point at NULL, and must have freed every pointers\n");
	ft_list_clear (&list);
	if (((void*)(rmem[0].next) == (void*)mem1->next) || ((void*)(rmem[1].next) == (void*)mem2->next))
		printf ("warning, pointers surely haven't been freed nor pointed at NULL\n");
	else if ((NULL == (void*)mem1->next) && (NULL == (void*)mem2->next))
		printf ("warning, pointers have been pointed at NULL but probably haven't been freed\n");
	else 
		printf ("probably OK\n");
	printf ("ft_list_clear() must make *begin_list point at NULL\n");
	if ((void*)list != NULL)
	{
		printf ("error: received %p\n", (void*)(list));
		return (1);
	}
	printf ("OK\n");
	printf ("ft_list_clear must run if length's list is 1\n");
	ft_list_clear (&list2);
	printf ("ft_list_clear() must make *begin_list point at NULL\n");
	if ((void*)list2 != NULL)
	{
		printf ("error: received %p\n", (void*)(list));
		return (1);
	}
	printf ("ft_list_clear must do nothing if *begin_list is NULL\n");
	ft_list_clear (&null);
	printf("ft_list_clear: OK\n");
	printf ("OK\n");
	return (0);
}
