#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	total;

	tab = NULL;
	total = (count * size);
	if (count != 0 && ((count * size) / count != size))
		return (NULL);
	tab = malloc(total);
	if (tab == NULL)
		return (NULL);
	memset(tab, 0, total);
	return (tab);
}