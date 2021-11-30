/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:43:50 by tedison           #+#    #+#             */
/*   Updated: 2021/06/09 17:46:25 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s_elem	*ft_lstnew(long long int nbr)
{
	t_s_elem	*new_elem;

	new_elem = malloc(sizeof(*new_elem) * 1);
	if (!new_elem)
		return (NULL);
	new_elem->nbr = nbr;
	new_elem->next = NULL;
	return (new_elem);
}
