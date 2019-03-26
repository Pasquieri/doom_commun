/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_info_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:43:14 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/01 17:08:19 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	extra_recup(char *str, int i, int x)
{
	while (str[i] != '(')
	{
		if (str[i] == '\0')
			return (-1);
		str[i] = ' ';
		i++;
	}
	str[i] = ' ';
	x = ft_atoi(str);
	while (str[i] != ',')
	{
		if (str[i] == '\0')
			return (-1);
		str[i] = ' ';
		i++;
	}
	str[i] = ' ';
	if (x > 0)
		return (x);
	else
		return (-1);
	return (0);
}

int			recup_info_player(char *str, char c)
{
	int		i;
	int		x;
	int		y;
	int		tmp;

	i = 0;
	x = 0;
	if (c == 'x')
	{
		tmp = extra_recup(str, i, x);
		if (tmp == -1)
			return (-1);
		else
			return (tmp);
	}
	else if (c == 'y')
	{
		y = ft_atoi(str);
		if (y > 0)
			return (y);
		else
			return (-1);
	}
	return (-1);
}
