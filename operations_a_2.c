/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:57:15 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 13:18:08 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 6;
}

void	rb_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 7;
}

void	rr_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 8;
}

void	rra_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 9;
}

void	rrb_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 10;
}
