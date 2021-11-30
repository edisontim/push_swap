/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:34:18 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 15:05:34 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_rec_two(t_s_info *i, int i_l, int i_h)
{
	if ((i->m[i_l] == 7 && i->m[i_h] == 10)
		|| (i->m[i_l] == 10 && i->m[i_h] == 7))
	{
		i->m[i_h] = -1;
		i->m[i_l] = -1;
		opti_rec_two(i, i_l - 1, i_h + 1);
	}
	else if ((i->m[i_l] == 6 && i->m[i_h] == 9)
		|| (i->m[i_l] == 9 && i->m[i_h] == 6))
	{
		i->m[i_h] = -1;
		i->m[i_l] = -1;
		opti_rec_two(i, i_l - 1, i_h + 1);
	}
	if ((i->m[i_l] == 4 && i->m[i_h] == 5)
		|| (i->m[i_l] == 5 && i->m[i_h] == 4))
	{
		i->m[i_h] = -1;
		i->m[i_l] = -1;
		opti_rec_two(i, i_l - 1, i_h + 1);
	}
}

void	opti_rec_one(t_s_info *i, int i_l, int i_h)
{
	if ((i->m[i_l] == 6 && i->m[i_h] == 7)
		|| (i->m[i_l] == 7 && i->m[i_h] == 6))
	{
		i->m[i_h] = -1;
		i->m[i_l] = 8;
		opti_rec_one(i, i_l - 1, i_h + 1);
	}
	else if ((i->m[i_l] == 9 && i->m[i_h] == 10)
		|| (i->m[i_l] == 10 && i->m[i_h] == 9))
	{
		i->m[i_h] = -1;
		i->m[i_l] = 11;
		opti_rec_one(i, i_l - 1, i_h + 1);
	}
}

void	opti_moves(t_s_info *info)
{
	int	i;

	i = 0;
	if (info->m == NULL || info->chunks == NULL)
		return ;
	while (info->m[i])
	{
		opti_rec_one(info, i, i + 1);
		opti_rec_two(info, i, i + 1);
		i++;
	}
}
