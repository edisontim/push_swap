/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:55:41 by tedison           #+#    #+#             */
/*   Updated: 2021/06/10 11:53:27 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*substr;
	int		start_cpy;

	if (!s)
		return (NULL);
	start_cpy = start;
	substr = NULL;
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start_cpy++] && i < len)
			i++;
	}
	substr = malloc(sizeof(*substr) * (i + 1));
	if (!substr)
		return (substr);
	i = 0;
	if (start < ft_strlen(s))
		while (s[start] && i < len)
			substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
