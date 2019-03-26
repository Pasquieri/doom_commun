/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:00:45 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/17 16:01:10 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	tmp;
	int	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			tmp = i;
			j = 0;
			while (haystack[tmp] == needle[j])
			{
				tmp++;
				j++;
				if (needle[j] == '\0')
					return ((char*)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
