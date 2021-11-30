/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:23:19 by tedison           #+#    #+#             */
/*   Updated: 2021/06/28 13:11:16 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_s_elem **a, t_s_elem **b, t_s_info *info)
{
	if (info->stack_size_a == 2)
		return (sort_two(a));
	if (info->stack_size_a == 3)
		sort_three(a);
	else if (info->stack_size_a <= 30)
		sort_small(a, b, info);
	else if (info->stack_size_a <= 100)
	{
		info->m = malloc(sizeof(long long int) * 1300);
		if (info->m == NULL)
			return (0);
		ft_bzero(info->m, sizeof(long long int) * 1300);
		sort_m_l(a, b, info, 7);
	}
	else
	{
		info->m = malloc(sizeof(long long int) * 12000);
		if (info->m == NULL)
			return (0);
		ft_bzero(info->m, sizeof(long long int) * 12000);
		sort_m_l(a, b, info, 15);
	}
	return (0);
}

int	ft_push_swap_string(t_s_elem **a, char **args, t_s_info *info)
{
	if (!args)
		return (0);
	if (!check_params(args))
		return (free_all(NULL, NULL, NULL, args));
	info->stack_size_a = stacks_init(args, a);
	if (!info->stack_size_a)
		return (free_all(NULL, NULL, NULL, args));
	info->chunk_size = info->stack_size_a;
	free_all(NULL, NULL, NULL, args);
	return (1);
}

int	push_swap_start(t_s_elem **a, t_s_elem **b, t_s_info *info)
{
	if (!info->stack_size_a)
		return (0);
	if (is_sorted(a))
		return (free_all(a, NULL, NULL, NULL));
	push_swap(a, b, info);
	if (info->stack_size_a > 30)
	{
		opti_moves(info);
		write_moves(info);
		free_all(NULL, NULL, info->m, NULL);
	}
	free_all(a, NULL, NULL, NULL);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_s_elem	*a;
	t_s_elem	*b;
	t_s_info	info;
	char		**args;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	ft_bzero((void *)&info, sizeof(info));
	if (argc == 2)
	{
		args = check_arg(argv[1]);
		if (!ft_push_swap_string(&a, args, &info))
			return (0);
	}
	else
	{
		if (!check_params(&argv[1]))
			return (0);
		info.stack_size_a = stacks_init(&argv[1], &a);
		info.chunk_size = info.stack_size_a;
	}
	return (push_swap_start(&a, &b, &info));
}
