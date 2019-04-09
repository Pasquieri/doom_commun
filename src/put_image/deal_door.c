/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:02:33 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/08 20:17:26 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	deal_door(t_env *env)
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
	//	cmp = env->sp[5].nb;
	}
}

/*void	deal_door(t_env *env) //utilise t_door au lieu de t_spr
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
}*/

void	do_door(t_env *env) /*idem : a modif*/
{
	int	i;
	int	j;
	int	a;

	i = (int)(env->coord_mur.x / env->coef);
	j = (int)(env->coord_mur.y / env->coef);
	a = -1;
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
