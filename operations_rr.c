/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:45:16 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 12:02:37 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ra(t_s_elem **a, int y)
{
	t_s_elem	*a_cpy;
	t_s_elem	*iter;

	if (!*a)
		return ;
	iter = *a;
	a_cpy = (*a)->next;
	while (iter->next)
		iter = iter->next;
	iter->next = (*a);
	(*a)->next = NULL;
	*a = a_cpy;
	if (y == 1)
		write(1, "ra\n", 3);
}

void	rb(t_s_elem **b, int y)
{
	t_s_elem	*b_cpy;
	t_s_elem	*iter;

	if (!*b)
		return ;
	iter = *b;
	b_cpy = (*b)->next;
	while (iter->next)
		iter = iter->next;
	iter->next = (*b);
	(*b)->next = NULL;
	*b = b_cpy;
	if (y == 1)
		write(1, "rb\n", 3);
}

void	rr(t_s_elem **a, t_s_elem **b, int y)
{
	ra(a, 0);
	rb(b, 0);
	if (y == 1)
		write(1, "rr\n", 3);
}

void	rra(t_s_elem **a, int y)
{
	t_s_elem	*last;
	t_s_elem	*buffer;

	if (!((*a)->next))
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	buffer = last;
	last = last->next;
	last->next = *a;
	*a = last;
	buffer->next = NULL;
	if (y == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_s_elem **b, int y)
{
	t_s_elem	*last;
	t_s_elem	*buffer;

	if (!(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
		last = last->next;
	buffer = last;
	last = last->next;
	last->next = *b;
	*b = last;
	buffer->next = NULL;
	if (y == 1)
		write(1, "rrb\n", 4);
}
