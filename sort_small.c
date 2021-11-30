/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:49:35 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 13:49:48 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_s_elem **a)
{
	if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		ra(a, 1);
		sa(a, 1);
	}
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		ra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		sa(a, 1);
	if ((*a)->nbr < (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		rra(a, 1);
	if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		rra(a, 1);
		sa(a, 1);
	}
}

int	stack_size(t_s_elem **first)
{
	t_s_elem	*iter;
	int			i;

	i = 0;
	iter = *first;
	while (iter)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}

int	sort_two(t_s_elem **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
	return (0);
}
