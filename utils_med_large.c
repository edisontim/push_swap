/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_med_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:42:13 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 13:42:32 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sc_bott(int *h_s, t_s_elem **f, t_s_info *info, int iter)
{
	t_s_elem	*iterator;
	int			index;

	index = 0;
	iterator = *f;
	while (iterator)
	{
		if (is_in_chunk(info, iterator->nbr, iter))
			*h_s = index;
		index++;
		iterator = iterator->next;
	}
	return (index);
}

void	bring_top_one(t_s_elem **f, t_s_info *info, int index, char c)
{
	int	i;

	i = 0;
	while (i++ < index)
	{
		if (c == 'a')
		{
			ra(f, 0);
			ra_a(info);
		}
		else
		{
			rb(f, 0);
			rb_a(info);
		}
	}
}

void	bring_top(t_s_elem **f, t_s_info *info, int index, char c)
{
	int		i;
	int		stack_size;

	i = 0;
	stack_size = info->stack_size_b;
	if (c == 'a')
		stack_size = info->stack_size_a;
	if (index <= stack_size / 2)
		bring_top_one(f, info, index, c);
	else
	{
		while (i++ < stack_size - index)
		{
			if (c == 'a')
			{
				rra(f, 0);
				rra_a(info);
			}
			else
			{
				rrb(f, 0);
				rrb_a(info);
			}
		}
	}
}

int	is_smaller(t_s_elem **first, int nbr)
{
	t_s_elem	*iter;

	if (first == NULL)
		return (1);
	iter = *first;
	while (iter)
	{
		if (nbr > iter->nbr)
			return (0);
		iter = iter->next;
	}
	return (1);
}

int	index_closest_inferior(t_s_elem **first, int nbr)
{
	t_s_elem	*iter;
	int			closest;
	int			i;
	int			index;

	index = 0;
	i = 0;
	iter = *first;
	closest = -2147483648;
	while (iter)
	{
		if (iter->nbr < nbr)
		{
			if (iter->nbr > closest)
			{
				closest = iter->nbr;
				index = i;
			}
		}
		i++;
		iter = iter->next;
	}
	return (index);
}
