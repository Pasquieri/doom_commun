/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_hor_shoot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:12:01 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 21:54:55 by cpalmier         ###   ########.fr       */
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

static void	check_shoot(t_env *env, t_coord cd, int i, int j)
{
	int		k;
	int		index_sp;
	double	dist;

	k = -1;
	index_sp = env->tab[j][i] - 10;
	while (++k < env->sp[index_sp].nb)
	{
		if (env->sp[index_sp].sprite[k].i == i
				&& env->sp[index_sp].sprite[k].j == j
				&& env->sp[index_sp].sprite[k].alive == 0)
		{
			dist = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
			dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
		//	env->sp[index_sp].sprite[k].detec[0].on = 1;
		//	env->sp[index_sp].sprite[k].detec[0].dist = dist;
		//	env->sp[index_sp].sprite[k].detec[0].cd = cd;
			env->shoot[0].val = env->tab[j][i];
			env->shoot[0].index = index_sp;
			env->shoot[0].k = k;
			env->shoot[0].det = 1;
			env->shoot[0].d = dist;
		}
	}
}

static void	ft_check_sprite(t_env *env, t_coord cd)
{
	int	i;
	int	j;

	if (env->angle > 0 && env->angle < 180)
		j = ((cd.y) - 1) / env->coef;
	else
		j = (int)(cd.y / env->coef);
	i = (int)(cd.x / env->coef);
	if ((env->tab[j][i] == WIN || env->tab[j][i] == MONKEY)
		&& env->shoot[0].det == 0)
		check_shoot(env, cd, i, j);
}

int	verif_hor_shoot(t_env *env, t_coord *coord)
{
	int	i;
	int	j;
	
	if (init_coord_lim(env, coord) == -1)
		return (-1);
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
		ft_check_sprite(env, *coord);
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
