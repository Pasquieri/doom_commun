/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:30:58 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/20 15:03:36 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_word(const char *str, char c)
{
	int i;
	int compteur;

	i = 0;
	compteur = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i - 1] != c && str[i - 1] != '\0')
			compteur++;
	}
	return (compteur);
}

static char	**ft_malloc(const char *str, char **dest, char c)
{
	int nb_char;
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < ft_nb_word(str, c))
	{
		nb_char = 0;
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			nb_char++;
		}
		dest[j] = (char *)malloc(sizeof(char) * (nb_char + 1));
		if (dest[j] == NULL)
			return (NULL);
		j++;
	}
	return (dest);
}

static char	**ft_filling(char const *str, char **dest, char c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (++i < ft_nb_word(str, c))
	{
		k = 0;
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j] != '\0')
			dest[i][k++] = str[j++];
		dest[i][k] = '\0';
	}
	dest[i] = NULL;
	return (dest);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**dest;

	dest = NULL;
	if (str)
	{
		dest = (char **)malloc(sizeof(char *) * (ft_nb_word(str, c) + 1));
		if (dest == NULL)
			return (NULL);
		dest = ft_malloc(str, dest, c);
		dest = ft_filling(str, dest, c);
	}
	return (dest);
}
