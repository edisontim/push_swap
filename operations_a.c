/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:09:32 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 13:17:45 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 1;
}

void	sb_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 2;
}

void	ss_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 3;
}

void	pa_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 4;
}

void	pb_a(t_s_info *info)
{
	int	i;

	i = 0;
	while (info->m[i] != 0)
		i++;
	info->m[i] = 5;
}
