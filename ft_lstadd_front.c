/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:54:56 by tedison           #+#    #+#             */
/*   Updated: 2021/05/31 10:20:27 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_s_elem **alst, t_s_elem *new)
{
	if (!alst || !new)
		return ;
	(*new).next = *alst;
	*alst = new;
}
