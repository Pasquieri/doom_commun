/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ver_shoot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:47:17 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 22:50:47 by cpalmier         ###   ########.fr       */
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
				&& env->sp[index_sp].sprite[k].j == j)
		{
			dist = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
			dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
		//	env->sp[index_sp].sprite[k].detec[1].on = 1;
		//	env->sp[index_sp].sprite[k].detec[1].dist = dist;
		//	env->sp[index_sp].sprite[k].detec[1].cd = cd;
//			env->shoot[1].val = env->tab[j][i];
//			env->shoot[1].det = 1;
//			env->shoot[1].index = index_sp;
//			env->shoot[1].k = k;
//			env->shoot[1].d = dist;
		}
	}
}

static void	ft_check_sprite(t_env *env, t_coord cd)
{
	int	i;
	int	j;

	if (env->angle > 90 && env->angle < 270)
		i = ((cd.x) - 1) / env->coef;
	else
		i = (int)(cd.x / env->coef);
	j = (int)(cd.y / env->coef);
	if ((env->tab[j][i] == WIN || env->tab[j][i] == MONKEY))
//		&& env->shoot[1].det == 0)
		check_shoot(env, cd, i, j);
}

int			verif_ver_shoot(t_env *env, t_coord *coord)
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
			coord->val = env->tab[j][i];
			return (1);
		}
		i = ((coord->x) - 1) / env->coef;
		if (env->tab[j][i] > 0 && env->tab[j][i] <= 7)
		{
			coord->val = env->tab[j][i];
			return (1);
		}
	}
	return (0);
}

