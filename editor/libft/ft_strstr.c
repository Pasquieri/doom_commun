/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:07:23 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/10 11:21:44 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] == '\0' && to_find[j] == '\0')
		return ((char *)s + i);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
