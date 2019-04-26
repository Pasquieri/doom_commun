/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_mur_hor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:12:01 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/26 18:12:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static int	init_coord_lim(t_env *env, t_coord *coord)
{
	int	lim;

	lim = env->x * env->coef;
	if (coord->x > lim || coord->y > lim || coord->x < 0 || coord->y < 0)
	{
		coord->x > lim ? coord->x = lim : coord->x;
		coord->y > lim ? coord->y = lim : coord->y;
		coord->x < 0 ? coord->x = 0 : coord->x;
		coord->y < 0 ? coord->y = 0 : coord->y;
		return (-1);
	}
	return (0);
}

static void	ft_check_sprite(t_env *env, int o, t_coord cd)
{
	int	i;
	int	j;

	if (env->angle > 0 && env->angle < 180)
		j = ((cd.y) - 1) / env->coef;
	else
		j = (int)(cd.y / env->coef);
	i = (int)(cd.x / env->coef);
	if (env->tab[j][i] == 10 || env->tab[j][i] == 11
			|| env->tab[j][i] == 15 || env->tab[j][i] == DOOR
			|| (env->tab[j][i] >= 4 && env->tab[j][i] <= 6))
		check_grid_win(env, cd, o, i, j);
	else
		check_sprite(i, j, env, o, cd);
}

int	verif_hor_sp(t_env *env, t_coord *coord)
{
	int	i;
	int	j;
	
	if (init_coord_lim(env, coord) == -1)
		return (-1);
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
		ft_check_sprite(env, 0, *coord);
		if (env->tab[j][i] > 0 && env->tab[j][i] <= 7)
		{
			coord->val = env->tab[j][i]; // pour les differents types de murs
			return (1);
		}
		j = ((coord->y) - 1) / env->coef;
		if (env->tab[j][i] > 0 && env->tab[j][i] <= 7)
		{
			coord->val = env->tab[j][i];
			return (1);
		}
	}
	return (0);
}
