/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_med_large_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:43:54 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 13:44:16 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_s_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->chunk_size - 1)
	{
		j = 0;
		while (j < info->chunk_size - i - 1)
		{
			if (info->chunks[j] < info->chunks[j + 1])
				swap(&info->chunks[j], &info->chunks[j + 1]);
			j++;
		}
		i++;
	}
}

int	get_index(t_s_elem **first, int nbr)
{
	t_s_elem	*iter;
	int			i;

	i = 0;
	iter = *first;
	while (iter)
	{œ
		if (iter->nbr == nbr)
			return (i);œ
		iter = iter->next;
		i++;
	}
	return (0);
}

int	is_in_chunk(t_s_info *info, int num, int iter)
{
	int	floor;
	int	ceiling;

	ceiling = info->chunks[0];
	floor = info->chunks[(info->chunk_size / info->num_chunk) *iter \
			+ (info->chunk_size / info->num_chunk - 1)];
	if (iter == info->num_chunk - 1)
		floor = info->chunks[info->chunk_size - 1];
	if (num >= floor && num <= ceiling)
		return (1);
	return (0);
}

int	chunk_init(t_s_elem **a, t_s_info *info)
{
	info->chunks = malloc(stack_size(a) * sizeof(int));
	if (info->chunks == NULL)
		return (0);
	fill_chunk(a, info);
	sort_chunk(info);
	return (1);
}

int	sc_top(int *hold_first, t_s_elem **first, t_s_info *info, int iter)
{
	t_s_elem	*iterator;
	int			index;

	iterator = *first;
	index = 0;
	while (iterator)
	{
		if (is_in_chunk(info, iterator->nbr, iter))
		{
			*hold_first = index;
			return (1);
		}
		index++;
		iterator = iterator->next;
	}
	return (0);
}
