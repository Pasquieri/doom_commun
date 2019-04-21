/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 03:55:38 by cpalmier          #+#    #+#             */
/*   Updated: 2019/04/21 19:58:12 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	print_gun(t_env *env, int k)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 600; // position dans la fenetre (x,y);
	y = 665;
	while (++y < 870)
	{
		x = 600;
		while (++x <= (600 + (env->lim_gun[k] - env->lim_gun[k - 1])))
		{
			i = 4 * x + y * env->m[0].s_l;
			j = 4 * (x - 600 + env->lim_gun[k - 1]) + (y - 665) * env->sp_t[6].s_l; // + lim[0] pour decaler la limite d'avant pour la bonne image
			if (env->sp_t[6].img_str[j + 3] != -1) // si pas transparent
			{
				env->m[0].img_str[i] = env->sp_t[6].img_str[j]; // sp[6] == gun
				env->m[0].img_str[i + 1] = env->sp_t[6].img_str[j + 1];
				env->m[0].img_str[i + 2] = env->sp_t[6].img_str[j + 2];
				env->m[0].img_str[i + 3] = env->sp_t[6].img_str[j + 3];
			}
		}
	}
}
