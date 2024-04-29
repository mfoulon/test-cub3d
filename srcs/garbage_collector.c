#include "cub3d.h"

static void	delete(void *ptr);
void		*ft_garbage_collector(void *ptr, bool clean);

void	*ft_garbage_collector(void *ptr, bool clean)
{
	static t_list	*garbage_list;

	if (clean)
	{
		ft_lstclear(&garbage_list, delete);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
		return (ptr);
	}
}

static void	delete(void *ptr)
{
	free(ptr);
	ptr = NULL;
}