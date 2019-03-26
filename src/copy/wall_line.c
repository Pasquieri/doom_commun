/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:50:34 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 17:58:15 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		wall_line(char *str, t_env *env)
{
	int		i;
	char	c;

	c = '0';
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\n' && str[i] != ' ')
		{
			free(str);
			return (error_message(12, env));
		}
		i++;
	}
	return (0);
}
