/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:28:17 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/27 16:35:26 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	free_error(char *p, int err, t_env *env)
{
	free(p);
	return (error_message(err, env));
}

static int	fill_condition_1(t_fill *fill, t_env *env)
{
	int	i;

	i = 0;
	fill->tmp = ft_strsplit(fill->line, ' ');
	if (tablen(fill->tmp) < env->perso_x)
		i = 14;
	if (verif_case(fill->tmp[(int)env->perso_x][0]) == -1)
		i = 15;
	fill->k = tablen(fill->tmp);
	while (fill->k >= 0)
	{
		free(fill->tmp[fill->k]);
		fill->k--;
	}
	free(fill->tmp);
	if (i == 15 || i == 14)
		return (free_error(fill->line, i, env));
	return (0);
}

static int	init_fill_tab(t_fill *fill, t_env *env)
{
	fill->nb_char = ft_strlen(fill->line);
	if (fill->nb_char == 0)
		return (free_error(fill->line, 13, env));
	fill->verif = verif_char(fill->line, env);
	if (fill->verif == -1)
		return (-1);
	if (fill->i == env->perso_y)
		if (fill_condition_1(fill, env) == -1)
			return (-1);
	return (0);
}

static int	fill_extra(t_env *env, t_fill *fill)
{
	if (init_fill_tab(fill, env) == -1)
		return (-1);
	fill->nb_sol += compte_char(fill->line, '0');
	fill->j = 0;
	fill->tmp = ft_strsplit(fill->line, ' ');
	if (verif_nb_tab(fill->tmp, env) == -1)
		return (-1);
	while (fill->j <= 41 && fill->tmp[fill->j])
	{
		env->tab[fill->i][fill->j] = ft_atoi(fill->tmp[fill->j]);
		free(fill->tmp[fill->j]);
		fill->j++;
	}
	free(fill->tmp);
	fill->i++;
	if (fill->i == env->y)
		if (wall_line(fill->line, env) == -1)
			return (-1);
	free(fill->line);
	fill->line = NULL;
	return (0);
}

int			fill_tab(int fd, t_env *env)
{
	t_fill fill;

	fill.nb_sol = 0;
	fill.i = 0;
	fill.line = NULL;
	fill.nb_char = -1;
	while (get_next_line(fd, &fill.line) == 1)
	{
		if (fill.i > 39)
			return (free_error(fill.line, 16, env));
		if (fill_extra(env, &fill) == -1)
			return (-1);
	}
	if (env->perso_y >= fill.i)
		return (free_error(fill.line, 14, env));
	if (fill.i != env->y)
		return (free_error(fill.line, 4, env));
	if (fill.nb_sol == 0)
		return (free_error(fill.line, 11, env));
	free(fill.line);
	return (0);
}
