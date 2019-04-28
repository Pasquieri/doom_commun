/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:02:33 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/28 16:04:45 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void		deal_door(t_env *env)
{
	int	i;
	int	j;
	int	cmp;

	cmp = -1;
	while (++cmp < env->sp[5].nb)
	{
		if (env->sp[5].sprite[cmp].proximity == 1)
		{
			i = env->sp[5].sprite[cmp].i;
			j = env->sp[5].sprite[cmp].j;
			if (env->tab[j][i] == 7)
			{
				env->tab[j][i] = 15;
				env->sp[5].sprite[cmp].open = 1;
			}
			else if (env->tab[j][i] == 15)
			{
				env->tab[j][i] = 7;
				env->sp[5].sprite[cmp].open = 0;
			}
		}
	}
}

void		deal_tab(t_env *env)
{
	int	cmp;

	cmp = -1;
	while (++cmp < env->sp[7].nb)
	{
		if (env->sp[7].sprite[cmp].proximity == 1)
		{
			if (env->skybox == 0)
				env->skybox = 24;
			else if (env->skybox == 24 || env->skybox == 22)
				env->skybox = 0;
		}
	}
}

static void	check_pos(t_env *env, int k, int cmp)
{
	double	spr_x;
	double	spr_y;

	spr_x = env->sp[k].sprite[cmp].cd.x;
	spr_y = env->sp[k].sprite[cmp].cd.y;
	if (env->sp[k].sprite[cmp].alive == 1)
	{
		if (env->perso_x >= (spr_x - 2) && env->perso_x <= (spr_x + 2)
				&& env->perso_y >= (spr_y - 2) && env->perso_y <= (spr_y + 2))
		{
			if (k == 3)
			{
				env->h_life += 30;
				system("/usr/bin/afplay -q 1 src/song/eat.mp3&");
			}
			else if (k == 6)
			{
				env->h_ammo += 15;
				system("/usr/bin/afplay -q 1 src/song/ammo.mp3&");
			}
			env->sp[k].sprite[cmp].alive = 0;
			env->tab[env->sp[k].sprite[cmp].j][env->sp[k].sprite[cmp].i] = 0;
		}
	}
}

void		deal_items(t_env *env, int k)
{
	int	cmp;
	int	i;
	int	j;

	i = (int)(env->perso_x / env->coef);
	j = (int)(env->perso_y / env->coef);
	cmp = -1;
	while (++cmp < env->sp[k].nb)
	{
		if (env->sp[k].sprite[cmp].i == i
				&& env->sp[k].sprite[cmp].j == j)
			check_pos(env, k, cmp);
	}
}
