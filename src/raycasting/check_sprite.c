/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:25:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/10 04:10:32 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/wolf3d.h"

void	check_sprite(int i, int j, t_env *env, int orientation, t_coord cd)
{
	int		value;
	int		k;
	int		index_sp;
	double	dist;

	value = -1;
	if (env->tab[j][i] >= 10 && env->tab[j][i] <= 15)
		value = env->tab[j][i];
	if (env->tab[j][i] == DOOR) // add
		value = DOOR; // add
	if (value != -1)
	{
		k = -1;
		index_sp = value - 10;
		value == DOOR ? index_sp = 5 : index_sp; // add
		while (++k < env->sp[index_sp].nb)
		{
			if (env->sp[index_sp].sprite[k].i == i
					&& env->sp[index_sp].sprite[k].j == j)
			{
				dist = sqrt(pow(env->perso_x - cd.x, 2) + pow(env->perso_y - cd.y, 2));
				dist = dist * cos((env->angle - env->d_regard) * M_PI / 180);
				env->sp[index_sp].sprite[k].detec[orientation].on = 1;
				env->sp[index_sp].sprite[k].detec[orientation].dist = dist;
				env->sp[index_sp].sprite[k].detec[orientation].cd = cd;
			}
		}
	}
}
