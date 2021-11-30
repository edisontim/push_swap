/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_med_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:35:53 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 13:57:49 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_closer_inferior(t_s_elem **first, t_s_info *info, int nbr)
{
	int	closest_inferior;

	closest_inferior = index_closest_inferior(first, nbr);
	bring_top(first, info, closest_inferior, 'b');
}

int	moves_to_top(t_s_info *info, int nbr)
{
	if (nbr > info->stack_size_a / 2)
		return (info->stack_size_a - nbr + 1);
	else
		return (nbr);
}

void	empty_b(t_s_elem **a, t_s_elem **b, t_s_info *info)
{
	bring_top(b, info, max_index(b), 'b');
	while (*b != NULL)
	{
		pa(a, b, 0);
		pa_a(info);
		info->stack_size_a++;
		info->stack_size_b--;
	}
}

void	sort_m(t_s_elem **a, t_s_elem **b, t_s_info *info, t_med *med)
{	
	if (sc_top(&med->h_f, a, info, med->i)
		&& sc_bott(&med->h_s, a, info, med->i))
	{
		if (med->h_f != med->h_s)
		{
			if (moves_to_top(info, med->h_f) < moves_to_top(info, med->h_s))
				bring_top(a, info, med->h_f, 'a');
			else
				bring_top(a, info, med->h_f, 'a');
		}
		else
			bring_top(a, info, med->h_f, 'a');
		if (is_smaller(b, (*a)->nbr))
			bring_top(b, info, max_index(b), 'b');
		else
			move_closer_inferior(b, info, (*a)->nbr);
		pb(a, b, 0);
		pb_a(info);
		info->stack_size_a--;
		info->stack_size_b++;
	}
	else
		med->i++;
}

int	sort_m_l(t_s_elem **a, t_s_elem **b, t_s_info *info, int n_m)
{
	t_med	med;

	med.h_f = 0;
	med.h_s = 0;
	info->num_chunk = n_m;
	med.i = 0;
	if (!chunk_init(a, info))
		return (0);
	while (med.i < n_m)
	{
		sort_m(a, b, info, &med);
	}
	empty_b(a, b, info);
	free(info->chunks);
	return (0);
}
