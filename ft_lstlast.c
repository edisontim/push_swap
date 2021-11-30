/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:13:24 by tedison           #+#    #+#             */
/*   Updated: 2021/05/31 10:18:13 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s_elem	*ft_lstlast(t_s_elem *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
