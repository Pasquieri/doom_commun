/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:29:40 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/12/14 16:40:36 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		white_space_at_end(char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new;
	int		k;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	j = white_space_at_end((char *)s);
	if (!(new = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	while (i + k < j)
	{
		new[k] = s[i + k];
		k++;
	}
	new[k] = '\0';
	return (new);
}
