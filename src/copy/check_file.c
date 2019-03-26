/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:23:08 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 19:12:24 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	check_file_extra(char *line1, int fd, t_env *env)
{
	env->x = ft_atoi(line1);
	env->y = ft_atoi(line1);
	free(line1);
	if (malloc_tab(env) == -1)
		return (-1);
	if (fill_tab(fd, env) == -1)
		return (-1);
	return (0);
}

static int	check_perso_coord(char **line1, int fd, t_env *env)
{
	env->perso_x = recup_info_player(*line1, 'x');
	env->perso_y = recup_info_player(*line1, 'y');
	if (env->perso_x != -1 && env->perso_y != -1)
	{
		free(*line1);
		if (get_next_line(fd, line1) != 1)
		{
			free(*line1);
			return (error_message(13, env));
		}
	}
	else
	{
		free(*line1);
		return (error_message(14, env));
	}
	return (0);
}

int			check_file(int fd, t_env *env)
{
	char	*line1;

	line1 = NULL;
	if (get_next_line(fd, &line1) != 1)
	{
		free(line1);
		return (error_message(13, env));
	}
	if (check_perso_coord(&line1, fd, env) == -1)
		return (-1);
	if (verif_valeur(line1, env) == -1)
		return (-1);
	if (check_file_extra(line1, fd, env) == -1)
		return (-1);
	return (0);
}
