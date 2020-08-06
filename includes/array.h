#ifndef ARRAY_H
# define ARRAY_H
# include "libft.h"

# define BH_LEFT(i)		(((i) << 1) + 1)
# define BH_RIGHT(i)	(((i) << 1) + 2)
# define BH_PARENT(i)	(((i) - 1) / 2)
# define AR_SWAP		((t_ar_opt1*)ar->opt)->swap
# define AR_CMP			((t_ar_opt1*)ar->opt)->cmp

typedef struct	s_array
{
	void		**data;
	size_t		len;
	size_t		cap;
	void		*opt;
}				t_array;

typedef struct	s_ar_opt
{
	int			(*cmp)(void*, void*);
	void		(*swap)(void*, void*);
}				t_ar_opt;

t_array			*ar_new(uint32_t cap);
int				ar_extend(t_array *ar, uint32_t extra_cap);
int				ar_add(t_array *ar, void *new);

int				bh_add(t_array *bh, void *new);
void			*bh_extract(t_array *bh);

t_ar_opt		*ar_opt(int (*cmp)(void*, void*), void (*swap)(void**, void**));

void			ar_quicksort(t_array *ar, uint32_t l, uint32_t r);

#endif