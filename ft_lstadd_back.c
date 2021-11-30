/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:18:37 by tedison           #+#    #+#             */
/*   Updated: 2021/06/01 16:04:21 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_s_elem **alst, t_s_elem *new)
{
	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
	ft_lstlast(*alst)->next = NULL;
}
