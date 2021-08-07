#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;
	mem = malloc(sizeof(mem) * size);
	if (mem == NULL)
		return (NULL);
	
}
