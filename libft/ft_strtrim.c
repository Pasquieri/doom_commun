/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:16:18 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/22 16:15:28 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_mod(const char *s)
{
	int	i;
	int compteur;

	i = 0;
	compteur = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		compteur++;
		i++;
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
	{
		i--;
		if (i < 0)
			return (0);
		compteur--;
	}
	return (compteur);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen_mod(s);
	dst = (char *)ft_memalloc(sizeof(char) * (len + 2));
	if (dst == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j <= len)
	{
		dst[j] = s[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
