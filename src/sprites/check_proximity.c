/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proximity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:53:39 by cpalmier          #+#    #+#             */
/*   Updated: 2019/05/01 19:47:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void			check_door_prox(t_env *env, t_coord cd, int i, int j)
{
	int		k;
	int		index_sp;
	double	dist;

	k = -1;
	if (env->tab[j][i] == DOOR || env->tab[j][i] == DOOR_CLOSE)
		index_sp = 5;
	if (env->tab[j][i] >= W_G_TAB && env->tab[j][i] <= W_B_TAB)
		index_sp = 7;
	while (++k < env->sp[index_sp].nb)
	{
		if (env->sp[index_sp].sprite[k].i == i
				&& env->sp[index_sp].sprite[k].j == j
				&& env->sp[index_sp].sprite[k].alive == 1)
		{
			dist = sqrt(pow(env->perso_x - cd.x, 2)
					+ pow(env->perso_y - cd.y, 2));
			dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
			env->sp[index_sp].sprite[k].detec[env->orientation].on = 1;
			env->sp[index_sp].sprite[k].detec[env->orientation].dist = dist;
		}
	}
}

static void		deal_proximity(double d_sprite, t_env *env, int k, int cmp)
{
	int	a;
	int	b;

	if (k == 5)
	{
		a = env->sp[k].sprite[cmp].i;
		b = env->sp[k].sprite[cmp].j;
		env->sp[k].sprite[cmp].open = 1;
		if (env->tab[b][a] == 7)
			env->sp[k].sprite[cmp].open = 0;
		if (d_sprite < (3 * env->coef / 2))
			env->sp[k].sprite[cmp].proximity = 1;
		else
			env->sp[k].sprite[cmp].proximity = 0;
	}
	else
	{
		if (d_sprite < env->coef)
			env->sp[k].sprite[cmp].proximity = 1;
		else
			env->sp[k].sprite[cmp].proximity = 0;
	}
}

static double	ft_distance(t_env *env, int k, int cmp)
{
	double	dist0;
	double	dist1;

	if (env->sp[k].sprite[cmp].detec[0].on == 1)
		dist0 = env->sp[k].sprite[cmp].detec[0].dist;
	else
		dist0 = env->sp[k].sprite[cmp].detec[1].dist + 1;
	if (env->sp[k].sprite[cmp].detec[1].on == 1)
		dist1 = env->sp[k].sprite[cmp].detec[1].dist;
	else
		dist1 = env->sp[k].sprite[cmp].detec[0].dist + 1;
	if (dist1 < dist0)
		return (dist1);
	return (dist0);
}

void			check_proximity(t_env *env)
{
	int		k;
	int		cmp;
	double	d_sprite;

	k = 4;
	while (++k < 8)
	{
		k == 6 ? k = 7 : k;
		cmp = -1;
		while (++cmp < env->sp[k].nb)
		{
			if ((env->sp[k].sprite[cmp].detec[0].on == 1)
					|| (env->sp[k].sprite[cmp].detec[1].on == 1))
			{
				d_sprite = ft_distance(env, k, cmp);
				if (d_sprite <= env->dist)
					deal_proximity(d_sprite, env, k, cmp);
			}
			env->sp[k].sprite[cmp].detec[0].on = 0;
			env->sp[k].sprite[cmp].detec[1].on = 0;
		}
	}
}
