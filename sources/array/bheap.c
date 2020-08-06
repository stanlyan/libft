#include "array.h"

void	bh_sift_down(t_array *ar, size_t i)
{
	size_t	left;
	size_t	right;
	size_t	lesser;

	while ((left = BH_LEFT(i)) < ar->len)
	{
		right = left + 1;
		lesser = left;
		if (right < ar->len && AR_CMP(ar->data[left], ar->data[right]) > 0)
			lesser = right;
		if (AR_CMP(ar->data[i], ar->data[lesser]) <= 0)
			break ;
		AR_SWAP(&ar->data[i], &ar->data[lesser]);
		lesser = i;
	}
}

void	bh_sift_up(t_array *ar, size_t i)
{
	size_t	parent;

	while (AR_CMP(ar->data[i], ar->data[(parent = BH_PARENT(i))]) < 0)
	{
		AR_SWAP(&ar->data[i], &ar->data[parent]);
		i = parent;
	}
}

int		bh_add(t_array *ar, void *new)
{
	if (ar_add(ar, new))
		return (1);
	bh_sift_up(ar, ar->len - 1);
	return (0);
}

void	*bh_extract(t_array *ar)
{
	void	*data;

	data = NULL;
	if (ar->len > 0)
	{
		data = ar->data[0];
		if (--ar->len > 0)
		{
			ar->data[0] = ar->data[ar->len];
			bh_sift_down(ar, 0);
		}
	}
	return (data);
}