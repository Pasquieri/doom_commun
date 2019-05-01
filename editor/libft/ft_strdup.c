/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:42:07 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/17 16:40:37 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlen_strdup(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *s)
{
	char	*new;
	int		i;
	int		len_s;

	new = NULL;
	i = 0;
	len_s = ft_strlen_strdup(s);
	if (!(new = (char *)malloc(sizeof(char) * (len_s + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
