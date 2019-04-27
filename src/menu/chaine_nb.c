/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaine_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:09:06 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/27 17:23:45 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int		ft_size(int nb)
{
	int			i;

	i = 0;
	while (nb > 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int		size_int(int nb)
{
	int			size;

	size = 1;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		size = size * 10;
	}
	return (size);
}

static char		*char_int(int nb)
{
	int			size;
	char		*tab;
	int			i;

	i = 0;
	size = size_int(nb);
	tab = NULL;
	tab = (char *)malloc(sizeof(char) * (ft_size(nb) + 1));
	if (tab == NULL)
		return ("");
	while (size)
	{
		tab[i] = ((nb / size) + '0');
		nb = nb % size;
		size = size / 10;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char			*chaine_nb(char *str, int nb, int i, int j)
{
	char		*res;
	char		*str2;

	res = NULL;
	str2 = char_int(nb);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str2) + ft_strlen(str) + 1));
	if (res == NULL)
		return ("");
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		res[i] = str2[j];
		i++;
		j++;
	}
	free(str2);
	res[i] = '\0';
	return (res);
}
