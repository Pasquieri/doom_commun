/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_info_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:56:40 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:42:47 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

static char	*remplit_str(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = ' ';
	return (str);
}

static int	recup_r(char *str, int i)
{
	while (str[i] != ',')
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	str = remplit_str(str, ',');
	return (ft_atoi(str));
}

static int	recup_x(char *str, int i, int x, char c)
{
	x++;
	if (c == 'x')
	{
		while (str[i] != '(')
		{
			if (str[i] == '\0')
				return (-1);
			i++;
		}
		str = remplit_str(str, '(');
		return (ft_atoi(str));
	}
	if (c == 'y')
	{
		while (str[i] != ',')
		{
			if (str[i] == '\0')
				return (-1);
			i++;
		}
		str = remplit_str(str, ',');
		return (ft_atoi(str));
	}
	return ((c == 'r') ? recup_r(str, i) : -1);
}

int			recup_info_player(char *str, char c)
{
	int		x;
	int		r;

	x = -1;
	r = -1;
	if (c == 'x')
		x = recup_x(str, 0, x, c);
	else if (c == 'y')
		x = recup_x(str, 0, x, c);
	else if (c == 'r')
		r = recup_x(str, 0, x, c);
	if (c == 'x' || c == 'y')
		return (((x < 1) || (x > 39)) ? -1 : x);
	else if (c == 'r')
		return ((r > 0 && r <= 360) ? r : -1);
	return (-1);
}
