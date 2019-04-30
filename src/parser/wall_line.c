/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:50:34 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:43:00 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

int		wall_line(char *str, t_env *env)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '2' && str[i] != '3' &&
			str[i] != '4' && str[i] != '5' && str[i] != '6' &&
			str[i] != '\n' && str[i] != ' ')
		{
			free(str);
			return (error_message(12, env));
		}
		i++;
	}
	return (0);
}
