/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:25:16 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/26 17:58:25 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	free_error(char *line1, t_env *env, int i)
{
	free(line1);
	return (error_message(i, env));
}

static int	check_file_extra(char *line1, int fd, t_env *env)
{
	env->x = 40;
	env->y = 40;
	free(line1);
	if (malloc_tab(env) == -1)
		return (-1);
	if (fill_tab(fd, env) == -1)
		return (-1);
	return (0);
}

static int	check_perso_coord(char *line1, t_env *env)
{
	env->perso_x = recup_info_player(line1, 'x');
	env->perso_y = recup_info_player(line1, 'y');
	env->perso_r = recup_info_player(line1, 'r');
	if (env->perso_x != -1 && env->perso_y != -1 && env->perso_r != -1)
		free(line1);
	else
		return (-1);
	return (0);
}

int			check_file(int fd, t_env *env)
{
	char	*line1;

	line1 = NULL;
	if (get_next_line(fd, &line1) != 1)
		return (free_error(line1, env, 13));
//	printf("et de un\n");
	if (check_perso_coord(line1, env) == -1)
		return (free_error(line1, env, 14));
//	printf("et de deux\n");
	if (get_next_line(fd, &line1) != 1)
		return (free_error(line1, env, 13));
	if (verif_valeur(line1, env) == -1)
		return (-1);
	if (check_file_extra(line1, fd, env) == -1)
		return (-1);
	return (0);
}
