/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:57:33 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 11:54:33 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_s_elem **first, int y)
{
	t_s_elem	*tampon;

	if (!first)
		return ;
	tampon = *first;
	*first = (*first)->next;
	tampon->next = (*first)->next;
	(*first)->next = tampon;
	if (y == 1)
		write(1, "sa\n", 3);
}

void	sb(t_s_elem **first, int y)
{
	t_s_elem	*tampon;

	if (!first)
		return ;
	tampon = *first;
	*first = (*first)->next;
	tampon->next = (*first)->next;
	(*first)->next = tampon;
	if (y == 1)
		write(1, "sb\n", 3);
}

void	ss(t_s_elem **a, t_s_elem **b, int y)
{
	if (!a || !b)
		return ;
	sa(a, 0);
	sb(b, 0);
	if (y == 1)
		write(1, "ss\n", 3);
}

void	pa(t_s_elem **a, t_s_elem **b, int y)
{
	t_s_elem	*tampon;

	if (!a || !b)
		return ;
	if (*b == NULL)
		return ;
	tampon = *b;
	*b = (*b)->next;
	tampon->next = *a;
	*a = tampon;
	if (y == 1)
		write(1, "pa\n", 3);
}

void	pb(t_s_elem **a, t_s_elem **b, int y)
{
	t_s_elem	*tampon;

	if (*a == NULL)
		return ;
	tampon = *a;
	*a = (*a)->next;
	tampon->next = *b;
	*b = tampon;
	if (y == 1)
		write(1, "pb\n", 3);
}
