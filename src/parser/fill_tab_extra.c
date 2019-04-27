/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:26:07 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/27 16:35:53 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		verif_case(char c)
{
	if (c == '8' || c == '0')
		return (0);
	return (-1);
}

int		verif_nb_tab(char **str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 40)
		return (0);
	return (error_message(8, env));
}

int		tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		i--;
	return (i);
}

int		compte_char(char *str, char c)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			x++;
		i++;
	}
	return (x);
}

int		verif_char(char *str, t_env *env)
{
	int	x;

	x = -1;
	while (str[++x])
	{
		if ((str[x] != '\0') && (str[x] != ' ') && ((str[x] <= 48)
					&& (str[x] >= 57)) && (str[x] != '\n') && (str[x] != '\t'))
		{
			free(str);
			return (error_message(7, env));
		}
	}
	return (x);
}
