/*
** DESCRIPTION
** The ft_realloc() function changes the size of the memory block bointed to by
** ptr to new_size bytes.
**
** RETURN VALUE
** The ft_memalloc() function returns a pointer to the memry area of new_size
** with data copied from ptr. If new_size is 0 or if an error occurs then the
** function returns 0.
**
** COMMENT
** Extra. Try to implement standard libc realloc func.
*/

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*x;

	if (!ptr)
		return (new_size ? malloc(new_size) : NULL);
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!(x = malloc(sizeof(new_size))))
		return (NULL);
	return (ft_memmove(x, ptr, new_size < old_size ? new_size : old_size));
}
