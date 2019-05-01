/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:18:26 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/17 16:41:40 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	if (s != NULL)
	{
		if (!(new = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			new[i] = s[i + start];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
