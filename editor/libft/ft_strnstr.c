/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:12:21 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/17 16:42:45 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && i < n)
	{
		j = 0;
		while (s[i + j] == to_find[j] && to_find[j] != '\0' && i + j < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
