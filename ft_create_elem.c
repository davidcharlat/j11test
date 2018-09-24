#include <stdlib.h>

#ifndef __FT_LIST_H__
# define __FT_LIST_H__

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
t_list				*ft_create_elem (void *data);

#endif /*!__FT_LIST_H__*/

t_list	*ft_create_elem (void *data)
{
	t_list	*ptr;
	
	ptr = (t_list*)malloc(sizeof(t_list));
	if (ptr)
	{
		ptr->data = data;
		ptr->next = NULL;
	}
	return (ptr);	
}
