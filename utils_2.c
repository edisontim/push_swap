/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:47:51 by tedison           #+#    #+#             */
/*   Updated: 2021/06/18 17:35:00 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_s_elem **a, t_s_elem **b, t_s_info *info)
{
	int	index;

	while (info->stack_size_a != 3)
	{
		index = min_index(a);
		while (index != 0)
		{
			if (index > info->stack_size_a / 2)
				rra(a, 1);
			else
				ra(a, 1);
			index = min_index(a);
		}
		info->stack_size_a--;
		pb(a, b, 1);
	}
	sort_three(a);
	while (*b != NULL)
		pa(a, b, 1);
}

int	max_index(t_s_elem **first)
{
	int						i;
	t_s_elem				*iter;
	long long int			max_value;
	int						index;

	if (!*first)
		return (0);
	index = 0;
	max_value = (*first)->nbr;
	iter = *first;
	i = 0;
	while (iter)
	{
		if (iter->nbr > max_value)
		{
			max_value = iter->nbr;
			index = i;
		}
		i++;
		iter = iter->next;
	}
	return (index);
}

int	min_index(t_s_elem **first)
{
	int				i;
	t_s_elem		*iter;
	long long int	min_value;
	int				index;

	if (!*first)
		return (0);
	index = 0;
	min_value = (*first)->nbr;
	iter = *first;
	i = 0;
	while (iter)
	{
		if (iter->nbr < min_value)
		{
			min_value = iter->nbr;
			index = i;
		}
		i++;
		iter = iter->next;
	}
	return (index);
}

int	fill_chunk(t_s_elem **a, t_s_info *info)
{
	t_s_elem	*iter;
	int			i;

	i = 0;
	iter = *a;
	while (iter)
	{
		info->chunks[i] = iter->nbr;
		i++;
		iter = iter->next;
	}
	i = 0;
	return (0);
}

void	swap(int *a, int *b)
{
	long long int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
