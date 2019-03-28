/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:02:33 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/28 19:03:46 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	deal_door(t_env *env)
{
	int	i;
	int	j;

	i = env->door.i;
	j = env->door.j;
	if (env->tab[j][i] == 7 && env->door.on)
	{
		env->tab[j][i] = 15;
		env->door.off = 1;
		env->door.on = 0;
	}
	else if (env->tab[j][i] == 15)
	{
		env->tab[j][i] = 7;
		env->door.off = 0;
	}
/*	i = env->door.i;
	j = env->door.j;
	if (env->tab[j][i] == 7 && env->door.on)
	{
		env->tab[j][i] = 15;
		env->door.off = 1;
		env->door.on = 0;
	}
	else if (env->tab[j][i] == 15)
	{
		env->tab[j][i] = 7;
		env->door.off = 0;
	}*/
}

void	do_door(t_env *env)
{
	int	i;
	int	j;
	int	a;

	i = (int)(env->coord_mur.x / env->coef);
	j = (int)(env->coord_mur.y / env->coef);
	a = -1;
/*	while (++a < env->spr[5].nb)
	{
		if ((env->spr->coord[a].i == i && env->spr->coord[a].j == j)
		|| (env->spr->coord[a].i == (i + 1) && env->spr->coord[a].j == j)
		|| (env->spr->coord[a].i == (i - 1) && env->spr->coord[a].j == j)
		|| (env->spr->coord[a].i == i && env->spr->coord[a].j == (j + 1))
		|| (env->spr->coord[a].i == i && env->spr->coord[a].j == (j - 1)))
		{
			env->spr->coord[a].on = 1;
			env->door.on = 1;
			env->door.off = 0;
		}
	}*/
	env->door.i = i;
	env->door.j = j;
	if (env->tab[j][i + 1] == 7)
		env->door.i = i + 1;
	else if (env->tab[j][i - 1] == 7)
		env->door.i = i - 1;
	else if (env->tab[j + 1][i] == 7)
		env->door.j = j + 1;
	else if (env->tab[j - 1][i] == 7)
		env->door.j = j - 1;
	env->door.on = 1;
	env->door.off = 0;
}