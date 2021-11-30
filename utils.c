/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:31:47 by tedison           #+#    #+#             */
/*   Updated: 2021/06/19 12:21:41 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_arg(char *argv_1)
{
	return (ft_split(argv_1, ' '));
}

void	write_more(t_s_info *info, int i)
{
	if (info->m[i] == 6)
		write(1, "ra\n", 3);
	if (info->m[i] == 7)
		write(1, "rb\n", 3);
	if (info->m[i] == 8)
		write(1, "rr\n", 3);
	if (info->m[i] == 9)
		write(1, "rra\n", 4);
	if (info->m[i] == 10)
		write(1, "rrb\n", 4);
	if (info->m[i] == 11)
		write(1, "rrr\n", 4);
}

void	write_moves(t_s_info *info)
{
	int	i;

	i = 0;
	if (info->m == NULL || info->chunks == NULL)
		return ;
	while (info->m[i] != 0)
	{
		if (info->m[i] == 1)
			write(1, "sa\n", 3);
		if (info->m[i] == 2)
			write(1, "sb\n", 3);
		if (info->m[i] == 3)
			write(1, "ss\n", 3);
		if (info->m[i] == 4)
			write(1, "pa\n", 3);
		if (info->m[i] == 5)
			write(1, "pb\n", 3);
		write_more(info, i);
		i++;
	}
}

int	is_sorted(t_s_elem **a)
{
	t_s_elem	*iter;

	iter = *a;
	while (iter->next)
	{
		if (iter->nbr > iter->next->nbr)
			return (0);
		iter = iter->next;
	}
	return (1);
}
